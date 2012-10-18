<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function elms_id_best_practices_ctools_plugin_api() {
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
function elms_id_best_practices_node_info() {
  $items = array(
    'elms_single_page' => array(
      'name' => t('Single page'),
      'module' => 'features',
      'description' => t('A page that can not be placed in a book outline'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function elms_id_best_practices_views_api() {
  return array(
    'api' => '2',
  );
}
