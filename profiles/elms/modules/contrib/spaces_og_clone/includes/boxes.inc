<?php
/**
 * @file
 * Enable the cloning of boxes and integration of boxes module
 */

/**
 * Implements hook_spaces_spaces_og_clone_spaces_overrides_alter().
 */
function boxes_spaces_og_clone_spaces_overrides_alter(&$overrides, $controller, $new_space, $old_space) {
  // Create a new box for each.
  if ($controller == 'boxes') {
    $new_overrides = array();
    foreach ($overrides as $object_id => $object_info) {
      // Find the new object ID.
      $new_object_id = preg_replace('/-\d+-/', '-' . $new_space->id . '-', $object_id);
      $object_info->delta = $new_object_id;
      $new_overrides[$new_object_id] = $object_info;
    }
    $overrides = $new_overrides;
  }
  // For contextes, we go through and update the delta based on the same
  // preg_replace as above.
  elseif ($controller == 'context') {
    foreach ($overrides as $context_key => $context) {
      if (!empty($context['blocks'])) {
        // Since we're readding the block in, need to prevent processing
        // processed blocks.
        $seen = array();
        foreach ($context['blocks'] as $block_id => $block_info) { 
          if ($block_info['module'] == 'boxes' && !isset($seen[$block_id])) {
            $new_delta =  preg_replace('/-\d+-/', '-' . $new_space->id . '-', $block_info['delta']);
            $block_info['delta'] = $new_delta;
            // Copy the old key to the new key location.
            $overrides[$context_key]['blocks']['boxes-' . $new_delta] = $block_info;
            // Remove the original key.
            unset($overrides[$context_key]['blocks'][$block_id]);
            $seen[] = 'boxes-' . $new_delta;
          }
        }
      }
    }
  }
}