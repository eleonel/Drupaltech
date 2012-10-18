<?php
/**
 * @file
 * Enable the cloning of nodes based on user roles in the group
 */

/**
 * Implements hook_spaces_og_clone_clone_settings().
 */
function user_spaces_og_clone_clone_settings($original_group) {
  $settings = array();
  $user_roles = user_roles();
  $settings['user_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Roles'),
    '#weight' => 1,
    '#description' => t("Select the user roles you want to include content from. Unchecking a role will exclude that role's content from the clone even if that Feature is being cloned above."),
    '#required' => TRUE,
    '#options' =>  $user_roles,
    '#default_value' => array_keys($user_roles),
  );

  return $settings;
}

/**
 * Implements hook_spaces_og_clone_node_query().
 */
function user_spaces_og_clone_node_query(&$query, $new_group, $old_group, $settings) {
  // Alter query based on role selection.
  if ($settings['user_roles'] && ($user_roles = array_filter($settings['user_roles']))) {
    $allow_auth = !empty($user_roles[DRUPAL_AUTHENTICATED_RID]);
    $allow_anon = !empty($user_roles[DRUPAL_ANONYMOUS_RID]);
    // Remove these roles as no reason to filter on them
    unset($user_roles[DRUPAL_AUTHENTICATED_RID], $user_roles[DRUPAL_ANONYMOUS_RID]);
    $add = FALSE;

    // Authenticated users are everyone but anoymous, ie user id is not 0.
    if ($allow_auth) {
      if (!$allow_anon) {
        $query['where']['uid'] = "n.uid > 0 ";
      }
    }
    // User wants to filter by role othen than authenticated..
    elseif ($user_roles) {
      $query['join']['user_roles'] = "LEFT JOIN {users_roles} as ur ON ur.uid = n.uid ";
      $query['args']['rids'] = array_keys($user_roles);

      $query['where']['rids'] = " (ur.rid IN (". db_placeholders($user_roles) .") ";
      // Consider user 1 as having all roles.
      $query['where']['rids'] .= "OR n.uid = 1 ";
      // If anonymous allowed, then uid of 0 is allowed.
      if ($allow_anon) {
        $query['where']['rids'] .= "OR n.uid = 0 ";
      }
      $query['where']['rids'] .= ") ";
    }
    // For some reason this cloner has only chosen anonymous. Weird.
    elseif ($allow_anon) {
      $query['where']['uid'] = "AND n.uid = 0 ";
    }
  }
}
