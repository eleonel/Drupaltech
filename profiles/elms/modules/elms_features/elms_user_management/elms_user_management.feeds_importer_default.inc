<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function elms_user_management_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'elms_user_xml_import';
  $feeds_importer->config = array(
    'name' => 'ELMS user xml import',
    'description' => 'Import users from XML feed',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(),
        'rawXML' => array(),
        'context' => '',
        'exp' => array(
          'errors' => FALSE,
          'tidy' => FALSE,
          'debug' => array(),
          'tidy_encoding' => 'UTF8',
        ),
        'allow_override' => TRUE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(),
        'update_existing' => FALSE,
        'status' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'profile_first_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'profile_last_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'og_roles',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'mail',
            'unique' => 1,
          ),
        ),
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['elms_user_xml_import'] = $feeds_importer;

  return $export;
}
