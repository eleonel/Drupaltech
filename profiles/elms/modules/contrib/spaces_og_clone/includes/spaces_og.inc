<?php
/**
 * @file
 * Enable the cloning of spaces / og specific settings
 */

/**
 * Implementaton of hook_spaces_og_clone_cloned().
 */
function spaces_og_spaces_og_clone_cloned($new_group, $old_group, $settings) {
  // Remove any overides just written in the node save as they may not be
  // exact clones.
  db_query("DELETE FROM {spaces_overrides} WHERE id=%d AND type = 'og'", $new_group->nid);
  $old_space = spaces_load('og', $old_group->nid);
  $new_space = spaces_load('og', $new_group->nid, TRUE);

  foreach (array_keys(spaces_controllers()) as $controller) {
    $overrides = $old_space->controllers->{$controller}->get(NULL, 'space');
    drupal_alter('spaces_og_clone_spaces_overrides', $overrides, $controller, $new_space, $old_space);
    foreach ($overrides as $id => $val) {
      $new_space->controllers->{$controller}->set($id, $val);
    }
  }

  // Copied from spaces_og_nodeapi.
  $selective = $new_space->controllers->variable->get('spaces_og_selective');
  $new_group->og_selective = $selective === NULL ? OG_OPEN : $selective;
  $register = $new_space->controllers->variable->get('spaces_og_register');
  $new_group->og_register = $register === NULL ? TRUE : $register;
  $directory = $new_space->controllers->variable->get('spaces_og_directory');
  $new_group->og_directory = $directory === NULL ? TRUE : $directory;
  $private = $new_space->controllers->variable->get('spaces_og_private');
  $new_group->og_private = $private === NULL ? FALSE : $private;
  og_update_group($new_group);
}
