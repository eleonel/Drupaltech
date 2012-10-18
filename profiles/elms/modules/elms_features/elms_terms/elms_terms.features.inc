<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function elms_terms_ctools_plugin_api() {
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
function elms_terms_node_info() {
  $items = array(
    'term' => array(
      'name' => t('Term'),
      'module' => 'features',
      'description' => t('Define a term for use in a course'),
      'has_title' => '1',
      'title_label' => t('Term'),
      'has_body' => '1',
      'body_label' => t('Definition'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function elms_terms_views_api() {
  return array(
    'api' => '2',
  );
}
