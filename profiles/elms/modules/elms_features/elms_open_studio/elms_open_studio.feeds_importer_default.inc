<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function elms_open_studio_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'blog_posts';
  $feeds_importer->config = array(
    'name' => 'Blog posts',
    'description' => 'Import blog posts into the open studio',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 1,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'exhibit_post',
        'input_format' => '1',
        'update_existing' => '0',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'author_name',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Blank source 1',
            'target' => 'field_exhibit_reference:nid',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
        'authorize' => 1,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['blog_posts'] = $feeds_importer;

  return $export;
}
