<?php
/**
 * @file
 * Enable the cleanup of node content post clone
 */

/**
 * Implements hook_spaces_og_clone_node_cleanup().
 */
function content_spaces_og_clone_node_cleanup(&$node, $group, $sandbox, $settings) {
  $info = content_types($node->type);
  $update_node = FALSE;
  foreach ($info['fields'] as $field_name => $field_info) {
    if ($field_info['module'] == 'text' && !empty($node->{$field_name})) {
      foreach ($node->{$field_name} as $delta => $values) {
        if (!empty($values['value'])) {
          $node->{$field_name}[$delta]['value'] = spaces_og_clone_replace_links($node->{$field_name}[$delta]['value'], $sandbox['nid_map']);
          $update_node = $update_node || ($node->{$field_name}[$delta]['value'] != $values['value']);
        }
      }
    }
    if ($field_info['module'] == 'link' && !empty($node->{$field_name})) {
      foreach ($node->{$field_name} as $delta => $values) {
        if (!empty($values['url'])) {
          $node->{$field_name}[$delta]['url'] = spaces_og_clone_replace_links($node->{$field_name}[$delta]['url'], $sandbox['nid_map']);
          $update_node = $update_node || ($node->{$field_name}[$delta]['url'] != $values['url']);
        }
      }
    }
  }

  return $update_node;
}
