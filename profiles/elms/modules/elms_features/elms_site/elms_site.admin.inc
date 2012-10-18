<?php
/**
 * @file
 * Admin container
 *
 * Creates the admin menu container for elms items
 */

/**
 * Menu callback; displays a module's settings page.
 */
function elms_site_settings_overview() {
  // Check database setup if necessary
  if (function_exists('db_check_setup') && empty($_POST)) {
    db_check_setup();
  }
  // create the elms admin container for adding settings to
  $item = menu_get_item('elms_site_admin');
  $content = system_admin_menu_block($item);
  $output = theme('admin_block_content', $content);
  return $output;
}

/**
 * Menu callback; displays a module's settings page.
 */
function elms_site_import_settings_overview() {
  // Check database setup if necessary
  if (function_exists('db_check_setup') && empty($_POST)) {
    db_check_setup();
  }
  // create the elms admin container for adding settings to
  $item = menu_get_item('elms_site_admin/import_export');
  $content = system_admin_menu_block($item);
  $output = theme('admin_block_content', $content);
  return $output;
}

/**
 * Menu callback; redirect to active site node id.
 */
function elms_site_edit_site() {
  $group = og_get_group_context();
  // if group id is set, redirect there
  if (isset($group->nid)) {
    drupal_goto('node/'. $group->nid .'/edit');
  }
}

/**
 * Menu callback; redirect to active site node id.
 */
function elms_site_edit_features() {
  $group = og_get_group_context();
  // if group id is set, redirect there
  if (isset($group->nid)) {
    drupal_goto('node/'. $group->nid .'/features');
  }
}

/**
 * Menu callback; redirect to active site node id.
 */
function elms_site_og_stats() {
  $group = og_get_group_context();
  // if group id is set, redirect there
  if (isset($group->nid)) {
    drupal_goto('node/'. $group->nid .'/og_stats');
  }
}
