<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function elms_navigation_top_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function elms_navigation_top_imagecache_default_presets() {
  $items = array(
    'elms_navigation_top' => array(
      'presetname' => 'elms_navigation_top',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '20px',
            'height' => '20px',
          ),
        ),
      ),
    ),
  );
  return $items;
}
