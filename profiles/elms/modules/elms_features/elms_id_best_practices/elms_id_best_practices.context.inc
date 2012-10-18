<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function elms_id_best_practices_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'elms_id_bp-instructor-contact';
  $context->description = 'Instructor contact block';
  $context->tag = 'ELMS ID Best Practices';
  $context->conditions = array(
    'context_spaces_features' => array(
      'values' => array(
        'elms_id_best_practices' => 'elms_id_best_practices',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'elms_id_best_practices-0' => array(
          'module' => 'elms_id_best_practices',
          'delta' => 0,
          'region' => 'left',
          'weight' => '31',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('ELMS ID Best Practices');
  t('Instructor contact block');
  $export['elms_id_bp-instructor-contact'] = $context;

  return $export;
}
