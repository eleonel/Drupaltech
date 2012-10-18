<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function elms_content_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function elms_content_flag_default_flags() {
  $flags = array();
  // Exported flag: "Bookmarks".
  $flags['bookmarks'] = array(
    'content_type' => 'node',
    'title' => 'Bookmarks',
    'global' => '0',
    'types' => array(
      '0' => 'page',
    ),
    'flag_short' => 'Bookmark this',
    'flag_long' => 'Add this post to your bookmarks',
    'flag_message' => 'This post has been added to your bookmarks',
    'unflag_short' => 'Unbookmark this',
    'unflag_long' => 'Remove this post from your bookmarks',
    'unflag_message' => 'This post has been removed from your bookmarks',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        '0' => 2,
      ),
      'unflag' => array(
        '0' => 2,
      ),
    ),
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'elms_content',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implementation of hook_node_info().
 */
function elms_content_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'module' => 'features',
      'description' => t('Create a page of content for use in site outlines.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Content'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'referenced_page' => array(
      'name' => t('Referenced page'),
      'module' => 'features',
      'description' => t('use this to reference other pieces of content.'),
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
function elms_content_views_api() {
  return array(
    'api' => '2',
  );
}
