<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function elms_schedule_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'elms_schedule-nav-right';
  $context->description = 'Right hand menu integration with schedule';
  $context->tag = 'ELMS Schedule';
  $context->conditions = array(
    'context_spaces_features' => array(
      'values' => array(
        'elms_schedule' => 'elms_schedule',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-elms_schedule-block_1' => array(
          'module' => 'views',
          'delta' => 'elms_schedule-block_1',
          'region' => 'regions_elms_navigation_right',
          'weight' => '7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('ELMS Schedule');
  t('Right hand menu integration with schedule');
  $export['elms_schedule-nav-right'] = $context;

  return $export;
}
