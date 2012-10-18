<?php

/**
 * @file
 * Main functions for cloning a group.
 */

/**
 * Clone a group (or finish up after a clone).
 */
function spaces_og_clone_clone($new_group, $old_group, $settings, $batch = FALSE) {
  global $user;

  // Set some default information if not set
  $settings += array(
    'uid' => $user->uid,
  );

  // Need to actually clone the group
  if (empty($new_group)) {
    $new_group = _spaces_og_clone_node_clean_group($old_group);
    $new_group->uid = $settings['uid'];
    $new_group->name = _spaces_og_fetch_user_name($new_group->uid);

    // spaces_og + node_save purl bug.
    if (module_exists('spaces_og') && $new_group->purl) {
      $new_group->purl = array('value' => $new_group->purl);
    }
    node_save($new_group);
  }
  $sogcid = spaces_og_clone_clone_map_insert($new_group, $old_group, $settings);
  $settings['sogcid'] = $sogcid;

  // This calling method allows $settings to be modified if desired.
  foreach (module_implements('spaces_og_clone_cloned') as $module) {
    $function = $module . '_spaces_og_clone_cloned';
    $function($new_group, $old_group, $settings);
  }

  // now copy all the content since we have a group we can copy into

  // If features were selected, grab the corresponding node types.
  $query = array(
    'joins' => array(
      'og_ancestry' => 'INNER JOIN {og_ancestry} as oga ON oga.nid = n.nid ',
    ),
    'where' => array(
      'group_nid' => 'oga.group_nid = %d'
    ),
    'args' => array('group_id' => $old_group->nid),
    'order' => array(),
  );

  foreach (module_implements('spaces_og_clone_node_query') as $module) {
    $function = $module . '_spaces_og_clone_node_query';
    $function($query, $new_group, $old_group, $settings);
  }
  drupal_alter('spaces_og_clone_node_query', $query, $new_group, $old_group, $settings);

  // In case args were given an array, merge them togeather into master array.
  $args = array();
  foreach ($query['args'] as $arg_array) {
    if (is_array($arg_array)) {
      $args = array_merge($args, $arg_array);
    }
    else {
      $args[] = $arg_array;
    }
  }

  $query = "SELECT n.nid FROM {node} as n "
    . implode($query['joins'], ' ')
    . 'WHERE ' . implode($query['where'], ' AND ')
    . ($query['order'] ? ' ORDER BY ' . implode($query['order'], ', ') : '');
  $result = db_query(db_rewrite_sql($query), $args);

  // Gather the NIDs to batch create.
  $nids = array();
  while ($nid = db_result($result)) {
    $nids[$nid] = $nid;
  }

  if ($nids) {
    // For a small number of nodes, just create them, don't bother with batch.
    if (!$batch || count($nids) <= (SPACES_OG_CLONE_BATCH_MAX_RUNS / 2)) {
      spaces_og_clone_node_clone_nodes($nids, $new_group, $settings);
    }
    else {
      $batch = array(
        'title' => t('Cloning content'),
        'progress_message' => t('Completed clone @current of @total.'),
        'operations' => array(
          array('_spaces_og_clone_node_clone_nodes_batch', array($nids, $new_group, $settings)),
        ),
        'init_message' => t('Cloning content from for @title to @new_title', array('@title' => $old_group->title, '@new_title' => $new_group->title)),
        'error_message' => t('An error has occured'),
        'finished' => '_spaces_og_clone_node_clone_finished',
        'file' => drupal_get_path('module', 'spaces_og_clone') . '/spaces_og_clone.inc',
      );
      batch_set($batch);
    }
  }
  return $new_group;
}

/**
 * Insert the record about the clone.
 */
function spaces_og_clone_clone_map_insert($new_group, $old_group, $settings) {
  global $user;
  $values = array(
    'clone_nid' => $new_group->nid,
    'original_nid' => $old_group->nid,
    'settings' => $settings,
    'uid' => $user->uid,
    'created' => time(), 
  );
  drupal_write_record('spaces_og_clone_clone_map', $values);
  return $values['sogcid'];
}

/**
 * Insert the record about the cloned node.
 */
function spaces_og_clone_nid_map_insert($clone_node, $original_group, $sogcid) {
  global $user;
  $values = array(
    'clone_nid' => $clone_node->nid,
    'original_nid' => $original_group->nid,
    'sogcid' => $sogcid,
  );
  drupal_write_record('spaces_og_clone_nid_map', $values);
}

/**
 * Fetches a map of NIDs for a specific community.
 *
 * @param $new_group_nid
 *   The NID of the group to look up NIDs for.
 */
function spaces_og_clone_get_cloned_node_nids($new_group_nid) {
  $result = db_query('SELECT clone_nid, original_nid FROM {spaces_og_clone_nid_map} INNER JOIN og_ancestry on clone_nid = nid WHERE group_nid = %d', $new_group_nid);
  $map = array();
  while ($pair = db_fetch_object($result)) {
    $map[$pair->original_nid] = $pair->clone_nid;
  }
  return $map;
}

/**
 * Given a node object, removes any non-cloneable information.
 */
function _spaces_og_clone_node_clean(&$node) {
  unset($node->nid);
  unset($node->vid);
  unset($node->path);
  unset($node->create);
  unset($node->revision_uid);
  unset($node->og_groups_both);

  // reset UUID
  if (module_exists('uuid')) {
    unset($node->uuid);
    unset($node->revision_uuid);
  }

  // reset workflow if it exists
  if (module_exists('workflow')) {
    unset($group->workflow);
    unset($group->_workflow);
  }

  // account for statistics if its enabled
  if (module_exists('og_statistics')) {
    unset($group->og_statistics);
  }
  drupal_alter('spaces_og_clone_node_preclone', $node);
}

/**
 * Given a group node object, clean up and adjust values.
 */
function _spaces_og_clone_node_clean_group($old_group) {
  global $user;
  // First create a cleaned up version of node
  $new_group = drupal_clone($old_group);
  _spaces_og_clone_node_clean($new_group);
  if ($new_group->title) {
    $new_group->title .= ' clone';
  }

  // Assign a unique purl.
  if (module_exists('purl') && $new_group->purl) {
    $purl = $new_group->purl . '-clone';
    $modifier = array(
      'provider' => 'spaces_og',
      'value' => $purl,
      'id' => NULL,
    );

    $i = 1;
    while (!purl_validate($modifier) && $i < 1000) {
      $i++;
      $modifier['value'] = $purl . '-' . $i;
    }

    $new_group->purl = $modifier['value'];

    // Try to make title unique also
    if ($i > 1) {
      $new_group->title .= ' ' . $i;
    }
  }
  // Set the owner of the node to current user.
  $new_group->uid = $user->uid;
  $new_group->name = $user->name;

  // Track the group we're cloning.
  $new_group->spaces_og_clone_group = $old_group;

  return $new_group;
}

/**
 * Clone a set of nodes.
 *
 * @param $nids
 *   An array of nids to clone to the new group.
 * @param $group
 *  An group object that the nodes are being cloned to.
 * @param $settings
 *   An array of additional settings.
 *    uid: The user uid to set to the author of the node.
 *    sogcid: the spaces og clone group clone this clone is from.
 *
 */
function spaces_og_clone_node_clone_nodes($nids, $group, $settings = array()) {
  spaces_og_clone_include_files();
  $sandbox = array(
    'group' => $group,
    'settings' => $settings,
    'book_map' => array(),
    'nid_map' => array(),
    'mlid_map' => array(),
    'sogcid' => 0,
  );
  _spaces_og_clone_first_pass($nids, $sandbox);
  _spaces_og_clone_second_pass($sandbox['nid_map'], $sandbox);
}

/**
 * Batch operation to clone posts from one group to a cloned group.
 */
function _spaces_og_clone_node_clone_nodes_batch($nids, $group, $settings, &$context) {
  spaces_og_clone_include_files();

  if (empty($context['sandbox'])) {
    // Initiate multistep processing.
    $context['sandbox']['nids'] = $nids;
    $context['sandbox']['max_nids'] = count($nids);
    $context['sandbox']['max'] = $context['sandbox']['max_nids'] * 2;
    $context['sandbox']['mlid_map'] = array();
    $context['sandbox']['book_map'] = array();
    $context['sandbox']['nid_map'] = array();
    $context['sandbox']['step'] = 1;
    $context['sandbox']['group'] = $group;
    $context['sandbox']['settings'] = $settings;
  }

  // Process the next 30 nodes.
  if ($context['sandbox']['step'] == 1) {

    $process = array_slice($context['sandbox']['nids'], 0, SPACES_OG_CLONE_BATCH_MAX_RUNS);
    _spaces_og_clone_first_pass($process, $context['sandbox']);
    $context['sandbox']['nids'] = array_slice($context['sandbox']['nids'], SPACES_OG_CLONE_BATCH_MAX_RUNS);

    // Multistep processing : report progress.
    $count = count($context['sandbox']['nids']);
    if ($count) {
      $context['finished'] = ($context['sandbox']['max'] - $context['sandbox']['max_nids']  - $count) / $context['sandbox']['max'];
    }
    // Now we indicate it's time to post process the nodes, to process node references.
    else {
      $context['finished'] = .5;
      $context['sandbox']['step'] = 2;
      $context['sandbox']['nids'] = $context['sandbox']['nid_map'];
    }
  }
  // Ugly, but it'll fall through and cancel the bulk if nodereference doesn't
  // Exist. This loop will likely be useful for some other type of update later.
  elseif ($context['sandbox']['step'] == 2) {
    $process = array_slice($context['sandbox']['nids'], 0, SPACES_OG_CLONE_BATCH_MAX_RUNS, TRUE);
    _spaces_og_clone_second_pass($process, $context['sandbox']);
    $context['sandbox']['nids'] = array_slice($context['sandbox']['nids'], SPACES_OG_CLONE_BATCH_MAX_RUNS, NULL, TRUE);

    $count = count($context['sandbox']['nids']);
    if ($count) {
      $context['finished'] = (($context['sandbox']['max']- $count) / $context['sandbox']['max']);
    }
  }
}

/**
 * First pass that creates all the nodes for the group
 */
function _spaces_og_clone_first_pass($nids, &$sandbox) {
  // Avoid any issues with the space not being active when creating nodes.
  if (module_exists('spaces_og')) {
    $current_space = spaces_get_space();
    $space = spaces_load('og', $sandbox['group']->nid);
    spaces_set_space($space);
  }
  foreach ($nids as $nid) {
    $node = node_load($nid);
    $old_node = drupal_clone($node);

    // Pass in old node for reference.
    $node->spaces_og_clone_original = $old_node;

    // set some common values to null so this will create a new node
    $node->log = "Original node nid: " . $node->nid;
    _spaces_og_clone_node_clean($node);
    $node->og_groups = array($sandbox['group']->nid => $sandbox['group']->nid);
    // change the user id to the one that the form dictates
    if (isset($sandbox['settings']['uid'])) {
      $node->uid = $sandbox['settings']['uid'];
    }
    // change the author name to match
    $node->name = _spaces_og_fetch_user_name($node->uid);
    // account for books
    if (isset($node->book['mlid'])) {
      // Clear the book and set new information.
      $node->book = array();

      // Need to maintain positioning at its level
      $node->book['weight'] = $old_node->book['weight'];
      // needed so it doesn't fall into menu hell
      $node->book['module'] = 'book';
      $node->book['bid'] = $old_node->book['plid'] == 0 || !isset($sandbox['book_map'][$old_node->book['bid']]) ? 'new' : $sandbox['book_map'][$old_node->book['bid']];
      // see if there's a match on a parent
      $node->book['plid'] = isset($sandbox['mlid_map'][$old_node->book['plid']]) ?$sandbox['mlid_map'][$old_node->book['plid']] : NULL;

      node_save($node);

      // map old mlid and nid to new one
      $sandbox['mlid_map'][$old_node->book['mlid']] = $node->book['mlid'];
      $sandbox['book_map'][$old_node->book['bid']] = $node->book['bid'];
    }
    else {
      node_save($node);
    }
    spaces_og_clone_nid_map_insert($node, $old_node, $sandbox['settings']['sogcid']);

    $sandbox['nid_map'][$old_node->nid] = $node->nid;
  }
  if (module_exists('spaces_og')) {
    spaces_set_space($current_space);
  }
}

/**
 * Any cleanup needed that the first node save was not able to handle.
 *
 * This is useful for things like nodereference where need to know all the nodes
 * before able to map correctly.
 */
function _spaces_og_clone_second_pass($nids, &$sandbox) {
  if (module_exists('spaces_og')) {
    $current_space = spaces_get_space();
    $space = spaces_load('og', $sandbox['group']->nid);
    spaces_set_space($space);
  }

  // Now we can update any references now that the new nodes exist.
  foreach ($nids as $old_nid => $new_nid) {
    $node = node_load($new_nid);
    $node->spaces_og_clone_original = node_load($old_nid);
    $update_node = FALSE;
    foreach (module_implements('spaces_og_clone_node_cleanup') as $module) {
      $function = $module . '_spaces_og_clone_node_cleanup';
      $update_node = $function($node, $sandbox['group'], $sandbox, $sandbox['settings']) || $update_node;
    }
      // If anything has changed, update the node.
    if ($update_node) {
      node_save($node);
    }
  }
  if (module_exists('spaces_og')) {
    spaces_set_space($current_space);
  }
}

/**
 * Processes a string, replacing old links with new.
 *
 * @param $text
 *   A string of text that may contain links to other content.
 * @param $map
 *   A map of NIDs from old NIDs to new NIDs.
 *
 * @return
 *   The processed string.
 * @see node_spaces_og_clone_node_cleanup.
 */
function spaces_og_clone_replace_links($text, $map) {
  static $maps = array();
  $key = implode('+', $map);
  if (!isset($maps[$key])) {
    $replacements = array(
      'original' => array(),
      'replacements' => array(),
    );
    foreach ($map as $old_nid => $new_nid) {
      $replacements['original'][] = 'node/' . $old_nid;
      $replacements['replacements'][] = 'node/' . $new_nid;
      $replacements['original'][] = url('node/' . $old_nid);
      $replacements['replacements'][] = url('node/' . $new_nid);
    }
    $maps[$key] = $replacements;
  }

  return str_replace($maps[$key]['original'], $maps[$key]['replacements'], $text);
}

/**
 * Fetch the name of the user.
 *
 * Since user_load is not cached and all we need is name, we use this.
 * (node_save doesn't work well without name set). 
 */
function _spaces_og_fetch_user_name($uid) {
  static $names;
  if (!isset($names[$uid])) {
    $names[$uid] = db_result(db_query('SELECT name from {users} WHERE uid = %d', $uid));
  }
  return $names[$uid];
}
