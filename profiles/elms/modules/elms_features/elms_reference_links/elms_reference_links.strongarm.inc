<?php

/**
 * Implementation of hook_strongarm().
 */
function elms_reference_links_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_content_links';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '4',
    'author' => '5',
    'options' => '6',
    'menu' => '-2',
    'book' => '2',
    'path' => '7',
    'og_nodeapi' => '0',
    'print' => '8',
    'workflow' => '3',
    'spaces_preset' => '9',
    'purl' => '-1',
    'themes' => '1',
  );
  $export['content_extra_weights_content_links'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_content_links';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_content_links'] = $strongarm;

  return $export;
}
