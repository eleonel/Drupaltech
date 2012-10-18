<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function elms_reference_links_ctools_plugin_api() {
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
function elms_reference_links_node_info() {
  $items = array(
    'content_links' => array(
      'name' => t('Content Links'),
      'module' => 'features',
      'description' => t('Associate reference links to content'),
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
function elms_reference_links_views_api() {
  return array(
    'api' => '2',
  );
}
