<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function elms_places_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function elms_places_node_info() {
  $items = array(
    'place' => array(
      'name' => t('Place'),
      'module' => 'features',
      'description' => t('Associate a place to content for use in views and display on maps'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => t('The title and body will be visible when a user clicks on the marker generated on the map.'),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function elms_places_views_api() {
  return array(
    'api' => '2',
  );
}
