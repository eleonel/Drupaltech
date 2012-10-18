<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function elms_resources_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function elms_resources_imagecache_default_presets() {
  $items = array(
    'elms_resource-list' => array(
      'presetname' => 'elms_resource-list',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '180',
            'height' => '',
            'upscale' => 1,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function elms_resources_node_info() {
  $items = array(
    'elms_resource' => array(
      'name' => t('ELMS Resource'),
      'module' => 'features',
      'description' => t('Resources for communicating information about resources used in a course'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Content'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
