<?php
/**
 * @file
 * Calls for all the pages associated to spaces_og_clone
 */

/**
 * Page callback for generic path that determines what form to call.
 */
function spaces_og_clone_clone_page($nid = NULL) {
  if ($nid) {
    return spaces_og_clone_clone_node_form(node_load($nid));
  }
  // @todo add in a jump menu
  else {
    $output = t('There is no groups that you are currently able to clone.');
    $create_types = array();
    foreach (og_get_types('group') as $type) {
      if (node_access('create', $type)) {
        $create_types[] = $type;
      }
    }
    if ($create_types) {
      $sql = "SELECT n.nid, n.title FROM {node} n WHERE n.type IN (" . db_placeholders($create_types, 'text') . ") AND n.status = 1 ORDER BY n.title ASC";
      $result = db_query(db_rewrite_sql($sql), $create_types);
      $rows = array();
      while ($row = db_fetch_object($result)) {
        $rows[] = l($row->title, 'spaces_og_clone/' . $row->nid);
      }
      if ($rows) {
        $output = theme('item_list', $rows);
      }
    }
    return $output;
  }
}


/**
 * Form defination for clone form.
 *
 * @see spaces_og_clone_clone_form_submit
 */
function spaces_og_clone_clone_node_form($old_group) {
  spaces_og_clone_include_files();
  module_load_include('inc', 'ctools', 'includes/form');
  module_load_include('inc', 'node', 'node.pages');

  $new_group = _spaces_og_clone_node_clean_group($old_group);
  return drupal_get_form($new_group->type . '_node_form', $new_group);
}

/**
 * Submit handler for spaces og clone clone form.
 */
function spaces_og_clone_clone_form_submit($form, &$form_state) {
  spaces_og_clone_include_files();
  $new_group = node_load($form_state['nid'], NULL, TRUE);
  $old_group = $form['#node']->spaces_og_clone_group;
  $new_group->spaces_og_clone_group = $old_group;

  $settings = !empty($form_state['values']['spaces_og_clone']) ? $form_state['values']['spaces_og_clone'] : array();
  $settings['name'] = $new_group->name;
  $settings['uid'] = $new_group->uid;

  spaces_og_clone_clone($new_group, $old_group, $settings, TRUE);
}
