<?php

/**
 * @file
 *  Spaces OG Clone module drush integration.
 */

/**
 * Implementation of hook_drush_command().
 */
function spaces_og_clone_drush_command() {
  $items = array();

  $items['spaces-og-clone-clone'] = array(
    'description' => "clone an organic group.",
    'drupal dependencies' => array('spaces_og_clone'),
    'aliases' => array('sogclone'),
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function spaces_og_clone_drush_help($section) {
  switch ($section) {
    case 'drush:spaces-og-clone-clone':
      return dt("Clone an organic group. Pass in a group NID. This command is to test cloning.");
  }
}

/**
 * Clone a group.
 */
function drush_spaces_og_clone_clone() {
  if (drush_get_context('DRUSH_SIMULATE')) {
    return;
  }
  if ($args = func_get_args()) {
    spaces_og_clone_include_files();
    foreach ($args as $arg) {
      if (is_numeric($arg)) {
        $node = node_load($arg);
        if ($node && og_is_group_type($node->type)) {
          // Copy group.
          $settings = array();
          $group = spaces_og_clone_clone(NULL, $node, $settings);
          if ($group) {
            drush_print(dt('Created Group @name [nid: @nid]', array('@name' => $group->title, '@nid' => $group->nid)));
          }
          else {
            drush_die('Unable to create group.');
          }
          return;
        }
      }
    }
  }
  
  drush_die('No valid organic group NID was supplied.');
}