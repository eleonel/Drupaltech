<?php
/**
 * @file
 * ID best practice pages
 *
 * place holders for pages created by this module
 */

/**
 * Display Syllabus Page
 */
function _elms_id_best_practices_page_syllabus() {
  // get the group
  $group = og_get_group_context();
  $type = variable_get('elms_id_bp_syllabus_type', '');
  // if nothing was set it should never load
  if ($type == '') {
    return FALSE;
  }
  elseif ($type == 'node') {
    $nid = _elms_id_best_practices_get_single_page($group->nid, 'Course syllabus');
    // go to the syllabus node if we found one
    if ($nid != FALSE) {
      return drupal_goto('node/'. $nid);
    }
    else {
      // set message that syllabus could not be found
      drupal_set_message('Syllabus could not be found.', 'error');
      return drupal_goto('node/'. $group->nid);
    }
  }
  else {
    // syllabus is just a document, send them there
    return l(t('Click to view the course syllabus (PDF)'), variable_get('elms_id_bp_syllabus', ''), array('attributes' => array('title' => t('View course syllabus (PDF)')), 'purl' => array('disabled' => TRUE)));
  }
}

/**
 * Display Help Page
 */
function _elms_id_best_practices_page_help() {
  // get the group
  $group = og_get_group_context();
  // if nothing was set it should never load
  if (variable_get('elms_id_bp_help', FALSE) == FALSE) {
    return FALSE;
  }
  else {
    $nid = _elms_id_best_practices_get_single_page($group->nid, 'Course help');
    // go to the syllabus node if we found one
    if ($nid != FALSE) {
      return drupal_goto('node/'. $nid);
    }
    else {
      // set message that syllabus could not be found
      drupal_set_message('Help page could not be found.', 'error');
      return drupal_goto('node/'. $group->nid);
    }
  }
}


/**
 * Settings form for book feature.
 */

function elms_id_best_practices_settings() {
  // create directory just in-case of first load
  $dir = file_create_path(file_directory_path() .'/syllabi');
  file_check_directory($dir,  1);
  $form = array();
  $form['elms_id_bp_syllabus_type'] = array(
    '#default_value' => variable_get('elms_id_bp_syllabus_type', ''),
    '#description' => t('How you want to treat the syllabus in the course, if its an uploaded file or a piece of content to edit.'),
    '#type' => 'select',
    '#options' => array('' => 'None', 'node' => 'Page of content', 'upload' => 'Uploaded file'),
    '#title' => t('Type of syllabus'),
  );
  $form['elms_id_bp_syllabus'] = array(
    '#default_value' => variable_get('elms_id_bp_syllabus', ''),
    '#description' => t('Upload your syllabus'),
    '#type' => 'file',
    '#size' => '10',
    '#title' => t('Syllabus'),
  );
  $form['elms_id_bp_help'] = array(
    '#default_value' => variable_get('elms_id_bp_help', ''),
    '#description' => t('Checking this box will create a help page to the resource section.'),
    '#type' => 'checkbox',
    '#title' => t('Help page'),
  );
  $form['elms_id_bp_instructor_block'] = array(
    '#default_value' => variable_get('elms_id_bp_instructor_block', ''),
    '#description' => t('Text to display in the instructor contact info block'),
    '#rows' => '3',
    '#cols' => '60',
    '#input_format' => '2',
    '#type' => 'textarea',
    '#title' => t('Instructor contact block'),
  );
  // render a select list based on a list of all available resources
  $result = db_query(db_rewrite_sql("SELECT nid,title FROM {node} as n WHERE n.type='elms_resource'"));
  $options = array();
  while ($val = db_fetch_array($result)) {
    $options[$val['nid']] = $val['title'];
  }
  $form['elms_id_bp_resources'] = array(
    '#default_value' => variable_get('elms_id_bp_resources', array()),
    '#description' => t('Select the resources you would like to use from the available list'),
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Resource list'),
    '#options' => $options,
  );
  // needs to be added so that we can successfully submit files
  $form['#attributes'] = array('enctype' => "multipart/form-data");
  $form['#validate'][] = 'elms_id_best_practices_settings_validate';
  $form['#submit'][] = 'elms_id_best_practices_settings_submit';
  return system_settings_form($form);
}

/**
 * Validation callback for id best practice feature settings.
 */
function elms_id_best_practices_settings_validate($form, &$form_state) {
  $form_state['storage']['elms_id_bp_syllabus'] = '';
  // create the theme logo area and validate its size
  $dir = file_create_path(file_directory_path() .'/syllabi');
  $is_writable = file_check_directory($dir, 1);
  // make sure folder is writable
  if ($is_writable) {
    // limit to 20 megs and pdf only
    $validators = array(
      'file_validate_size' => array(20 * 1024),
      'file_validate_extensions' => array('pdf'),
    );
    // attempt to save file
    if ($file = file_save_upload('elms_id_bp_syllabus', $validators, $dir)) {
      $form_state['storage']['elms_id_bp_syllabus'] = str_replace(' ', '%20', $file->filepath);
      $form_state['values']['elms_id_bp_syllabus'] = str_replace(' ', '%20', $file->filepath);
    }
  }
}

/**
 * Submit handler for id best practice feature settings.
 */
function elms_id_best_practices_settings_submit($form, &$form_state) {
  $group = og_get_group_context();
  $title = 'Course syllabus';
  $nid = _elms_id_best_practices_get_single_page($group->nid, $title);
  // create a node based on if syllabus is set to this
  if ($form_state['values']['elms_id_bp_syllabus_type'] == 'node') {    
    // make node if none was found
    if ($nid == FALSE) {
      _elms_id_best_practices_make_single_page($group, $title);
    }
    else {
      // ensure its published
      $node = node_load($nid);
      $node->status = 1;
      node_save($node);
    }
  }
  else {
    // unpublish the node if it exists and another option is set
    if ($nid != FALSE) {
      $node = node_load($nid);
      $node->status = 0;
      node_save($node);
    }
  }
  // account for help single node
  $title = 'Course help';
  $nid = _elms_id_best_practices_get_single_page($group->nid, $title);
  // create a node based on elms_id_bp_help setting
  if ($form_state['values']['elms_id_bp_help'] == 1) {
    // make node if none was found
    if ($nid == FALSE) {
      _elms_id_best_practices_make_single_page($group, $title);
    }
    else {
      // ensure its published
      $node = node_load($nid);
      $node->status = 1;
      node_save($node);
    }
  }
  else {
    // unpublish the node if it exists and another option is set
    if ($nid != FALSE) {
      $node = node_load($nid);
      $node->status = 0;
      node_save($node);
    }
  }
}

/**
 * Helper function to return a solo page based on title
 */
function _elms_id_best_practices_get_single_page($gnid, $title) {
  // select the special type of node elms_id_bp provides
  $result = db_query("SELECT {node}.nid FROM {og_ancestry} JOIN {node} ON {node}.nid = {og_ancestry}.nid WHERE type='elms_single_page' AND group_nid=%d AND title='%s'", $gnid, $title);
  $val = db_fetch_array($result);
  if (isset($val['nid'])) {
    return $val['nid'];
  }
  else {
    return FALSE;
  }
}

/**
 * Helper function to generate a solo page
 */
function _elms_id_best_practices_make_single_page($group, $title) {
  global $user;
  $node = new stdClass();
  // current user
  $node->uid = $user->uid;
  // custom type for this feature
  $node->type = 'elms_single_page';
  // title we'll be looking for
  $node->title = check_plain($title);
  // @todo: set default format
  $node->format = 1;
  // set it to unpublished
  $node->status = 0;
  // revision by default
  $node->revision = 1;
  // leave a log message
  $node->log = 'ELMS '. check_plain($title) .' page automatically created';
  // group set
  $node->og_groups = array($group->nid => $group->nid);
  $node->og_groups_both = array($group->nid => $group->title);
  // allow other modules to add in specific changes here
  drupal_alter('elms_single_page_build', $node);
  node_save($node);
  return $node->nid;
}