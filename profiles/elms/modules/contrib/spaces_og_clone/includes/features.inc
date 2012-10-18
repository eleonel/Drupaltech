<?php
/**
 * @file
 * Enable cloning selection based on feature
 */

/**
 * Implements hook_spaces_og_clone_clone_settings().
 */
function features_spaces_og_clone_clone_settings($original_group) {
  // user roles
  $settings = array();

  // Prepare the feature selection element via finding all valid features.
  $space = module_exists('spaces') ? spaces_load('og', $original_group->nid) : FALSE;
  $enabled_features = $space ? $space->controllers->variable->get('spaces_features') : FALSE;
  $features = spaces_features('og');
  $features_options = $features_node_map = array();
  foreach ($features as $feature_name => $feature_info) {
    // If we know the current space, only show enabled options, else show all.
    if (!empty($feature_info->info['features']['node']) && (!$enabled_features || !empty($enabled_features[$feature_name]))) {
      $features_options[$feature_name] = $feature_info->info['name'];
      $features_node_map[$feature_name] = $feature_info->info['features']['node'];
    }
  }

  $settings['features'] = array(
    '#default_value' => array_keys($features_options),
    '#description' => t('Select the Features that you want to clone as part of this OG clone'),
    '#weight' => 1,
    '#type' => 'checkboxes',
    '#options' => $features_options,
    '#title' => t('Features'),
  );
  // Keep track of what node types map to what features so don't need to
  // recalculate it later.
  $settings['features_node_map'] = array(
    '#type' => 'value',
    '#value' => $features_node_map,
  );

  return $settings;
}

/**
 * Implements hook_spaces_og_clone_node_query().
 */
function features_spaces_og_clone_node_query(&$query, $new_group, $old_group, $settings) {
  if (!empty($settings['features'])) {
    $content_types = array();
    $feature_map = $settings['features_node_map'];
    foreach (array_filter($settings['features']) as $feature_name => $enabled) {
      if (!empty($feature_map[$feature_name])) {
        $content_types = array_merge($content_types, $feature_map[$feature_name]);
      }
    }
    $content_types = array_unique($content_types);
    // build the query if we found anything
    if ($content_types) {
      $query['where']['feature_content_types'] = " n.type IN (" . db_placeholders($content_types, 'text') . ") ";
      $query['args']['feature_content_types'] = $content_types;
    }
  }
}
