<?php
/**
 * Render a feeds import form on import/[config] pages.
 */
function elms_user_management_admin_form() {
  // load in all available feeds
  $feeds = feeds_importer_load_all();
  // only find the ones that are user import objects
  foreach ($feeds as $importer) {
    if (get_class($importer->processor) == 'FeedsUserProcessor') {
      $user_importers[$importer->id] = $importer->config['name'];
    }
  }
  // Select the name
  $form['elms_um_importer'] = array(
    '#type' => 'select',
    '#options' => $user_importers,
    '#title' => 'Feed for import',
    '#description' => 'This feed will be the one primarily used for the import of users into sites.',
    '#default_value' => variable_get('elms_um_importer', ''),
  );
  // base address
  $form['elms_um_importer_address'] = array(
    '#type' => 'textfield',
    '#title' => 'Base import address',
    '#description' => 'The base address for remote calls. If your import routine does not have a remote address then ignore this. This is useful for connecting to remote systems ithout people needing to know the entire address',
    '#default_value' => variable_get('elms_um_importer_address', ''),
    '#maxlength' => 200,
  );
  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
  return $form;
}

/**
 * Submit handler for elms_user_management_admin_form().
 */
function elms_user_management_admin_form_submit($form, &$form_state) {
  // store values
  drupal_set_message('Settings saved!');
  variable_set('elms_um_importer', check_plain($form_state['values']['elms_um_importer']));
  variable_set('elms_um_importer_address', check_plain($form_state['values']['elms_um_importer_address']));
  
}

/**
 * Menu callback; displays a module's settings page.
 */
function elms_user_management_settings_overview() {
  // Check database setup if necessary
  if (function_exists('db_check_setup') && empty($_POST)) {
    db_check_setup();
  }
  // create the elms admin container for adding settings to
  $item = menu_get_item('elms_site_admin/user_management');
  $content = system_admin_menu_block($item);
  $output = theme('admin_block_content', $content);
  return $output;
}

/**
 * Menu callback; redirect to active site node id.
 */
function elms_user_management_view_roster() {
  $group = og_get_group_context();
  // if group id is set, redirect there
  if (isset($group->nid)) {
    drupal_goto('node/'. $group->nid .'/roster');
  }
}

/**
 * Menu callback; redirect to active site node id.
 */
function elms_user_management_xml_import() {
  $group = og_get_group_context();
  // if group id is set, redirect there
  if (isset($group->nid)) {
    drupal_goto('import/elms_user_xml_import');
  }
}

/**
 * Menu callback; redirect to active site node id.
 */
function elms_user_management_file_import() {
  $group = og_get_group_context();
  // if group id is set, redirect there
  if (isset($group->nid)) {
    drupal_goto('import/elms_user_file_import');
  }
}

/**
 * Break out form for dropping users.
 */
function elms_user_management_user_form_drop($form_state) {
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('User name'),
    '#required' => TRUE,
    '#element_validate' => array('elms_user_management_validate_name')
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Drop user'),
    '#weight' => 20,
    );
  return $form;
}

/**
 * Break out form for dropping users.
 */
function elms_user_management_user_form_drop_submit($form, &$form_state) {
  $group = og_get_group_context();
  // try loading the user
  $account = user_load(array('name' => check_plain($form_state['values']['name'])));
  // if account loads, drop the user from this group
  if (isset($account->uid)) {
    $group = og_get_group_context();
    drupal_set_message(t("@name has been successfully removed from site @group", array('@name' => $account->name, '@group' => $group->title)));
    // delete subscription for the user from the active group
    og_delete_subscription($group->nid, $account->uid);
  }
  else {
drupal_set_message(t("@name is not a valid user, no action taken.", array('@name' => $account->name)), 'error');  }
  
}

/**
 * Break out form for creating users.
 */
function elms_user_management_user_form($form_state) {
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('User name'),
    '#required' => TRUE,
    '#element_validate' => array('elms_user_management_validate_name'),
    '#description' => t('User name to create, this must be unique. If the user already exists then this will simply add the user as a member of this site'),
  );
  $form['mail'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),
    '#required' => TRUE,
    '#element_validate' => array('elms_user_management_validate_mail'),
  );
  $form['mail_confirm'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail (confirm)'),
    '#required' => TRUE,
  );
  $form['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('User roles'),
  );
  foreach (user_roles() as $rid => $role) {
    // Exclude 'anonymous user' and admin
    if ($rid !== 1 && $rid !== 3) {
      $form['roles'][$rid] = array(
        '#title' => $role,
        '#type' => 'checkbox',
        '#default_value' => $rid === 2,
        '#disabled' => $rid === 2 ? TRUE : FALSE,
      );
    }
  }
  // The personal welcome message will be added to the top of the mail.
  $form['welcome_message_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Personal welcome message'),
    '#default_value' => '',
    '#description' => t('This welcome message will appear at the top of the e-mail notification sent to the new user.')
    );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add user'),
    '#weight' => 20,
    );
  return $form;
}

/**
 * Element validator for usernames.
 */
function elms_user_management_validate_name($element, &$form_state) {
  if ($error = user_validate_name($element['#value'])) {
    form_set_error('name', $error);
  }
}

/**
 * Element validator for mail.
 */
function elms_user_management_validate_mail($element, &$form_state) {
  if ($form_state['values']['mail_confirm'] !== $element['#value']) {
    form_set_error('mail_confirm', t('E-mail addresses don\'t match'));
  }
  elseif (user_load(array('mail' => $element['#value']))) {
    form_set_error('mail', t('User with this e-mail address already exists.'));
  }
  elseif ($error = user_validate_mail($element['#value'])) {
    form_set_error('mail', $error);
  }
}

/**
 * Submit handler for elms_user_management_user_form().
 */
function elms_user_management_user_form_submit($form, &$form_state) {
  // If user roles were handled through a UI element, process accordingly.
  // This sucks. See user_save() for why this is necessary.
  if ($form['roles']['#type'] != 'value' && is_array($form_state['values']['roles'])) {
    $rids = array();
    foreach ($form_state['values']['roles'] as $rid => $enabled) {
      if (!empty($enabled)) {
        $rids[$rid] = $rid;
      }
    }
    $form_state['values']['roles'] = $rids;
  }
  else {
    // assign authenticated user role if nothing was defined
    $form_state['values']['roles'] = array(2 => 2);
  }
  // verify that this account exists, otherwise create it
  $account = user_load(array('name' => check_plain($form_state['values']['name'])));
  if (isset($account->uid)) {
    $group = og_get_group_context();
    og_save_subscription($group->nid, $account->uid, array('is_active' => 1));
    drupal_set_message(t("@name has been successfully added to site @group", array('@name' => $account->name, '@group' => $group->title)));
  }
  else {
    elms_user_management_user_create($form_state['values']);
  }
}