<?php

/**
 * Implementation of hook_feeds_tamper_default().
 */
function elms_user_management_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'elms_user_xml_import-xpathparser_0-convert_case';
  $feeds_tamper->importer = 'elms_user_xml_import';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['elms_user_xml_import-xpathparser_0-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'elms_user_xml_import-xpathparser_4-drupal_roles';
  $feeds_tamper->importer = 'elms_user_xml_import';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'role_map';
  $feeds_tamper->settings = array(
    'role_map_2' => '',
    'role_map_3' => '',
    'role_map_6' => '',
    'role_map_4' => 'instructor',
    'role_map_9' => '',
    'role_map_10' => 'student',
    'role_map_8' => 'teaching assistant',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Drupal roles';
  $export['elms_user_xml_import-xpathparser_4-drupal_roles'] = $feeds_tamper;

  return $export;
}
