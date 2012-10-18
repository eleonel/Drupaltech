<?php
/**
 * @file
 * Enable the repairing of node references within cloned nodes
 */

/**
 * Implements hook_sspaces_og_clone_node_cleanup().
 */
function nodereference_spaces_og_clone_node_cleanup($node, $group, $sandbox, $settings) {
  static $fields;
  if (!isset($fields)) {
    $fields = array();
    foreach (content_fields() as $field_name => $field_info) {
      if ($field_info['type'] == 'nodereference') {
        $fields[] = $field_name;
      }
    }
  }

  $update_node = FALSE;
  $map = $sandbox['nid_map'];
  foreach ($fields as $field_name) {
    if (!empty($node->{$field_name})) {
      foreach ($node->{$field_name} as $delta => $val) {
        if (!empty($val['nid'])) {
          // This node referenced another that was copied.
          if (!empty($map[$val['nid']])) {
            $node->{$field_name}[$delta]['nid'] = $map[$val['nid']];
            $update_node = TRUE;
          }
          // See if node was part of old group and was not copied.
          // We don't want to touch out of group/global references.
          else {
            $referenced_node = node_load($val['nid']);
            if (!empty($referenced_node->og_groups) && in_array($group->spaces_og_clone_group->nid, $referenced_node->og_groups)) {
              unset($node->{$field_name}[$delta]);
              $update_node = TRUE;
            }
          }
        }
      }
    }
  }
  return $update_node;
}