<?php
/**
 * @file
 * Enable the repair of links within cloned node body
 */

/**
 * Implements hook_spaces_og_clone_node_cleanup().
 */
function node_spaces_og_clone_node_cleanup($node, $group, $sandbox, $settings) {
  $old_body = $node->body;
  if (!empty($node->body) && !empty($sandbox['nid_map'])) {
    $node->body = spaces_og_clone_replace_links($node->body, $sandbox['nid_map']);
  }
  return $old_body != $node->body;
}