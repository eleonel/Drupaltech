<?php

/**
 * @file
 * Hooks provided by Spaces OG Clone.
 */


/**
 * Return settings your module provides for spaces OG cloning.
 *
 * Eah item in the array should be structured as if adding to a form.
 */
function hook_spaces_og_clone_clone_settings($original_group) {
  return array(
    'value_of_setting' => array(
      '#title' => t('My Options'),
      '#options' => array(0, 1),
      '#type' => 'select',
    ),
  );
}

/**
 * Alter the settings for cloning.
 */
function hook_spaces_og_clone_clone_settings_alter(&$settings, $original_group) {
  $settings['value_of_setting']['#options'][] = 2;
}


/**
 * Respond to clone happening.
 */
function hook_spaces_og_clone_cloned($new_group, $old_group, $settings) {

}

/**
 * Edit the items that are overridden for the new space.
 */
function hook_spaces_og_clone_spaces_overrides_alter(&$overrides, $controller, $new_space, $old_space) {

}

/**
 * Allow adding to the query.that is run to fetch what nodes to run.
 */
function hook_spaces_og_clone_node_query(&$query, $new_group, $old_group, $settings) {

}

/**
 * Second pass cleanup (for like fixing node reference fields.
 *
 * Return TRUE if node needs to be resaved.
 */
function hook_spaces_og_clone_node_cleanup($node, $group, $context_info, $settings) {

}

/**
 * Alter a node that will be cloned (remove values that should not be cloned.
 */
function hook_spaces_og_clone_node_preclone_alter($node) {

}
