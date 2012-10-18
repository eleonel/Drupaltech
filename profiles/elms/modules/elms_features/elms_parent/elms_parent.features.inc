<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function elms_parent_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function elms_parent_imagecache_default_presets() {
  $items = array(
    'parent_promo' => array(
      'presetname' => 'parent_promo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '600',
            'height' => '340',
          ),
        ),
      ),
    ),
    'parent_promo_listing' => array(
      'presetname' => 'parent_promo_listing',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '150',
            'height' => '100',
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
function elms_parent_node_info() {
  $items = array(
    'parent' => array(
      'name' => t('Course'),
      'module' => 'features',
      'description' => t('Use this to setup a name space to associate group instances to'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function elms_parent_views_api() {
  return array(
    'api' => '2',
  );
}
