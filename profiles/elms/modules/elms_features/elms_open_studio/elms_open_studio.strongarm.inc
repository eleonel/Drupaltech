<?php

/**
 * Implementation of hook_strongarm().
 */
function elms_open_studio_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_allowed_exhibit';
  $strongarm->value = array(
    0 => 1,
  );
  $export['better_formats_allowed_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_allowed_exhibit_audio';
  $strongarm->value = array(
    0 => 2,
  );
  $export['better_formats_allowed_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_allowed_exhibit_image';
  $strongarm->value = array(
    0 => 1,
  );
  $export['better_formats_allowed_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_allowed_exhibit_post';
  $strongarm->value = array(
    0 => 1,
  );
  $export['better_formats_allowed_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'better_formats_allowed_exhibit_video';
  $strongarm->value = array(
    0 => 1,
  );
  $export['better_formats_allowed_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_exhibit';
  $strongarm->value = 0;
  $export['comment_anonymous_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_exhibit_audio';
  $strongarm->value = 0;
  $export['comment_anonymous_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_exhibit_image';
  $strongarm->value = 0;
  $export['comment_anonymous_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_exhibit_post';
  $strongarm->value = 0;
  $export['comment_anonymous_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_exhibit_video';
  $strongarm->value = 0;
  $export['comment_anonymous_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_exhibit';
  $strongarm->value = '3';
  $export['comment_controls_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_exhibit_audio';
  $strongarm->value = '3';
  $export['comment_controls_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_exhibit_image';
  $strongarm->value = '3';
  $export['comment_controls_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_exhibit_post';
  $strongarm->value = '3';
  $export['comment_controls_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_exhibit_video';
  $strongarm->value = '3';
  $export['comment_controls_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_exhibit';
  $strongarm->value = '4';
  $export['comment_default_mode_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_exhibit_audio';
  $strongarm->value = '4';
  $export['comment_default_mode_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_exhibit_image';
  $strongarm->value = '4';
  $export['comment_default_mode_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_exhibit_post';
  $strongarm->value = '4';
  $export['comment_default_mode_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_exhibit_video';
  $strongarm->value = '4';
  $export['comment_default_mode_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_exhibit';
  $strongarm->value = '2';
  $export['comment_default_order_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_exhibit_audio';
  $strongarm->value = '2';
  $export['comment_default_order_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_exhibit_image';
  $strongarm->value = '2';
  $export['comment_default_order_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_exhibit_post';
  $strongarm->value = '2';
  $export['comment_default_order_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_exhibit_video';
  $strongarm->value = '2';
  $export['comment_default_order_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_exhibit';
  $strongarm->value = '300';
  $export['comment_default_per_page_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_exhibit_audio';
  $strongarm->value = '300';
  $export['comment_default_per_page_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_exhibit_image';
  $strongarm->value = '300';
  $export['comment_default_per_page_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_exhibit_post';
  $strongarm->value = '300';
  $export['comment_default_per_page_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_exhibit_video';
  $strongarm->value = '300';
  $export['comment_default_per_page_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_exhibit';
  $strongarm->value = '2';
  $export['comment_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_exhibit_audio';
  $strongarm->value = '2';
  $export['comment_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_exhibit_image';
  $strongarm->value = '2';
  $export['comment_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_exhibit_post';
  $strongarm->value = '2';
  $export['comment_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_exhibit_video';
  $strongarm->value = '2';
  $export['comment_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_exhibit';
  $strongarm->value = '1';
  $export['comment_form_location_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_exhibit_audio';
  $strongarm->value = '1';
  $export['comment_form_location_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_exhibit_image';
  $strongarm->value = '1';
  $export['comment_form_location_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_exhibit_post';
  $strongarm->value = '1';
  $export['comment_form_location_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_exhibit_video';
  $strongarm->value = '1';
  $export['comment_form_location_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_exhibit';
  $strongarm->value = '0';
  $export['comment_preview_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_exhibit_audio';
  $strongarm->value = '0';
  $export['comment_preview_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_exhibit_image';
  $strongarm->value = '0';
  $export['comment_preview_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_exhibit_post';
  $strongarm->value = '0';
  $export['comment_preview_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_exhibit_video';
  $strongarm->value = '0';
  $export['comment_preview_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_exhibit';
  $strongarm->value = '0';
  $export['comment_subject_field_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_exhibit_audio';
  $strongarm->value = '0';
  $export['comment_subject_field_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_exhibit_image';
  $strongarm->value = '0';
  $export['comment_subject_field_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_exhibit_post';
  $strongarm->value = '0';
  $export['comment_subject_field_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_exhibit_video';
  $strongarm->value = '0';
  $export['comment_subject_field_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_exhibit_audio';
  $strongarm->value = array(
    'title' => '104',
    'body_field' => '106',
    'revision_information' => '113',
    'author' => '114',
    'options' => '115',
    'comment_settings' => '116',
    'menu' => '110',
    'book' => '112',
    'path' => '118',
    'og_nodeapi' => '111',
    'print' => '117',
    'workflow' => '109',
    'spaces_preset' => '119',
    'purl' => '108',
    'themes' => '107',
  );
  $export['content_extra_weights_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_exhibit_post';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-1',
    'revision_information' => '4',
    'author' => '5',
    'options' => '6',
    'comment_settings' => '9',
    'menu' => '-4',
    'book' => '3',
    'path' => '7',
    'og_nodeapi' => '0',
    'print' => '8',
    'workflow' => '2',
    'spaces_preset' => '10',
    'purl' => '-3',
    'themes' => '1',
  );
  $export['content_extra_weights_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_exhibit_video';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '5',
    'author' => '6',
    'options' => '7',
    'comment_settings' => '10',
    'menu' => '-4',
    'book' => '4',
    'path' => '8',
    'og_nodeapi' => '-1',
    'print' => '9',
    'workflow' => '1',
    'spaces_preset' => '11',
    'purl' => '-3',
    'themes' => '0',
  );
  $export['content_extra_weights_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emfield_emaudio_allow_soundcloud';
  $strongarm->value = 1;
  $export['emfield_emaudio_allow_soundcloud'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_comment_exhibit';
  $strongarm->value = '0';
  $export['fivestar_comment_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_comment_exhibit_audio';
  $strongarm->value = '0';
  $export['fivestar_comment_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_comment_exhibit_image';
  $strongarm->value = '0';
  $export['fivestar_comment_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_comment_exhibit_post';
  $strongarm->value = '0';
  $export['fivestar_comment_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_comment_exhibit_video';
  $strongarm->value = '0';
  $export['fivestar_comment_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_exhibit';
  $strongarm->value = 1;
  $export['fivestar_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_exhibit_audio';
  $strongarm->value = 1;
  $export['fivestar_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_exhibit_image';
  $strongarm->value = 1;
  $export['fivestar_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_exhibit_post';
  $strongarm->value = 1;
  $export['fivestar_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_exhibit_video';
  $strongarm->value = 1;
  $export['fivestar_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_feedback_exhibit';
  $strongarm->value = 1;
  $export['fivestar_feedback_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_feedback_exhibit_audio';
  $strongarm->value = 1;
  $export['fivestar_feedback_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_feedback_exhibit_image';
  $strongarm->value = 1;
  $export['fivestar_feedback_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_feedback_exhibit_post';
  $strongarm->value = 1;
  $export['fivestar_feedback_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_feedback_exhibit_video';
  $strongarm->value = 1;
  $export['fivestar_feedback_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_labels_enable_exhibit';
  $strongarm->value = 1;
  $export['fivestar_labels_enable_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_labels_enable_exhibit_audio';
  $strongarm->value = 1;
  $export['fivestar_labels_enable_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_labels_enable_exhibit_image';
  $strongarm->value = 1;
  $export['fivestar_labels_enable_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_labels_enable_exhibit_post';
  $strongarm->value = 1;
  $export['fivestar_labels_enable_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_labels_enable_exhibit_video';
  $strongarm->value = 1;
  $export['fivestar_labels_enable_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_labels_exhibit';
  $strongarm->value = array(
    0 => 'Cancel rating',
    1 => 'Poor',
    2 => 'Okay',
    3 => 'Good',
    4 => 'Great',
    5 => 'Awesome',
    6 => 'Give it @star/@count',
    7 => 'Give it @star/@count',
    8 => 'Give it @star/@count',
    9 => 'Give it @star/@count',
    10 => 'Give it @star/@count',
  );
  $export['fivestar_labels_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_labels_exhibit_audio';
  $strongarm->value = array(
    0 => 'Cancel rating',
    1 => 'Poor',
    2 => 'Okay',
    3 => 'Good',
    4 => 'Great',
    5 => 'Awesome',
    6 => 'Give it @star/@count',
    7 => 'Give it @star/@count',
    8 => 'Give it @star/@count',
    9 => 'Give it @star/@count',
    10 => 'Give it @star/@count',
  );
  $export['fivestar_labels_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_labels_exhibit_image';
  $strongarm->value = array(
    0 => 'Cancel rating',
    1 => 'Poor',
    2 => 'Okay',
    3 => 'Good',
    4 => 'Great',
    5 => 'Awesome',
    6 => 'Give it @star/@count',
    7 => 'Give it @star/@count',
    8 => 'Give it @star/@count',
    9 => 'Give it @star/@count',
    10 => 'Give it @star/@count',
  );
  $export['fivestar_labels_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_labels_exhibit_post';
  $strongarm->value = array(
    0 => 'Cancel rating',
    1 => 'Poor',
    2 => 'Okay',
    3 => 'Good',
    4 => 'Great',
    5 => 'Awesome',
    6 => 'Give it @star/@count',
    7 => 'Give it @star/@count',
    8 => 'Give it @star/@count',
    9 => 'Give it @star/@count',
    10 => 'Give it @star/@count',
  );
  $export['fivestar_labels_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_labels_exhibit_video';
  $strongarm->value = array(
    0 => 'Cancel rating',
    1 => 'Poor',
    2 => 'Okay',
    3 => 'Good',
    4 => 'Great',
    5 => 'Awesome',
    6 => 'Give it @star/@count',
    7 => 'Give it @star/@count',
    8 => 'Give it @star/@count',
    9 => 'Give it @star/@count',
    10 => 'Give it @star/@count',
  );
  $export['fivestar_labels_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_position_exhibit';
  $strongarm->value = 'below';
  $export['fivestar_position_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_position_exhibit_audio';
  $strongarm->value = 'below';
  $export['fivestar_position_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_position_exhibit_image';
  $strongarm->value = 'below';
  $export['fivestar_position_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_position_exhibit_post';
  $strongarm->value = 'below';
  $export['fivestar_position_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_position_exhibit_video';
  $strongarm->value = 'below';
  $export['fivestar_position_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_position_teaser_exhibit';
  $strongarm->value = 'hidden';
  $export['fivestar_position_teaser_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_position_teaser_exhibit_audio';
  $strongarm->value = 'hidden';
  $export['fivestar_position_teaser_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_position_teaser_exhibit_image';
  $strongarm->value = 'hidden';
  $export['fivestar_position_teaser_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_position_teaser_exhibit_post';
  $strongarm->value = 'hidden';
  $export['fivestar_position_teaser_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_position_teaser_exhibit_video';
  $strongarm->value = 'hidden';
  $export['fivestar_position_teaser_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_stars_exhibit';
  $strongarm->value = '5';
  $export['fivestar_stars_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_stars_exhibit_audio';
  $strongarm->value = '5';
  $export['fivestar_stars_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_stars_exhibit_image';
  $strongarm->value = '5';
  $export['fivestar_stars_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_stars_exhibit_post';
  $strongarm->value = '5';
  $export['fivestar_stars_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_stars_exhibit_video';
  $strongarm->value = '5';
  $export['fivestar_stars_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_style_exhibit';
  $strongarm->value = 'average';
  $export['fivestar_style_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_style_exhibit_audio';
  $strongarm->value = 'average';
  $export['fivestar_style_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_style_exhibit_image';
  $strongarm->value = 'smart';
  $export['fivestar_style_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_style_exhibit_post';
  $strongarm->value = 'average';
  $export['fivestar_style_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_style_exhibit_video';
  $strongarm->value = 'average';
  $export['fivestar_style_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_text_exhibit';
  $strongarm->value = 'dual';
  $export['fivestar_text_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_text_exhibit_audio';
  $strongarm->value = 'dual';
  $export['fivestar_text_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_text_exhibit_image';
  $strongarm->value = 'dual';
  $export['fivestar_text_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_text_exhibit_post';
  $strongarm->value = 'dual';
  $export['fivestar_text_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_text_exhibit_video';
  $strongarm->value = 'dual';
  $export['fivestar_text_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_title_exhibit';
  $strongarm->value = 1;
  $export['fivestar_title_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_title_exhibit_audio';
  $strongarm->value = 1;
  $export['fivestar_title_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_title_exhibit_image';
  $strongarm->value = 1;
  $export['fivestar_title_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_title_exhibit_post';
  $strongarm->value = 1;
  $export['fivestar_title_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_title_exhibit_video';
  $strongarm->value = 1;
  $export['fivestar_title_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_unvote_exhibit';
  $strongarm->value = 1;
  $export['fivestar_unvote_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_unvote_exhibit_audio';
  $strongarm->value = 0;
  $export['fivestar_unvote_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_unvote_exhibit_image';
  $strongarm->value = 1;
  $export['fivestar_unvote_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_unvote_exhibit_post';
  $strongarm->value = 1;
  $export['fivestar_unvote_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fivestar_unvote_exhibit_video';
  $strongarm->value = 1;
  $export['fivestar_unvote_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_soundcloud_color_play';
  $strongarm->value = '#dbe8ff';
  $export['media_soundcloud_color_play'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_soundcloud_comments';
  $strongarm->value = 1;
  $export['media_soundcloud_comments'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_vimeo__color';
  $strongarm->value = '#01AAEA';
  $export['media_vimeo__color'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_vimeo__color_override';
  $strongarm->value = 0;
  $export['media_vimeo__color_override'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_vimeo__full_screen';
  $strongarm->value = 1;
  $export['media_vimeo__full_screen'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_vimeo__on_screen_info';
  $strongarm->value = array(
    'title' => 'title',
    'portrait' => 0,
    'byline' => 0,
  );
  $export['media_vimeo__on_screen_info'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_vimeo__thumb_size';
  $strongarm->value = '200';
  $export['media_vimeo__thumb_size'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_vimeo__universal';
  $strongarm->value = 1;
  $export['media_vimeo__universal'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__check_for_duplicates';
  $strongarm->value = 0;
  $export['media_youtube__check_for_duplicates'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__check_for_failed';
  $strongarm->value = 0;
  $export['media_youtube__check_for_failed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__check_for_rejected';
  $strongarm->value = 0;
  $export['media_youtube__check_for_rejected'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__colors_color1';
  $strongarm->value = '#FFFFFF';
  $export['media_youtube__colors_color1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__colors_color2';
  $strongarm->value = '#CCCCCC';
  $export['media_youtube__colors_color2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__cron_limit';
  $strongarm->value = '50';
  $export['media_youtube__cron_limit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__cron_time';
  $strongarm->value = '10';
  $export['media_youtube__cron_time'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__display_info';
  $strongarm->value = 1;
  $export['media_youtube__display_info'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__full_screen';
  $strongarm->value = 1;
  $export['media_youtube__full_screen'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__high_quality';
  $strongarm->value = 1;
  $export['media_youtube__high_quality'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__html5_player';
  $strongarm->value = 1;
  $export['media_youtube__html5_player'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__show_border';
  $strongarm->value = 0;
  $export['media_youtube__show_border'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__show_colors';
  $strongarm->value = 0;
  $export['media_youtube__show_colors'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__show_related_videos';
  $strongarm->value = 0;
  $export['media_youtube__show_related_videos'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__status_display_0';
  $strongarm->value = '';
  $export['media_youtube__status_display_0'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__status_display_duplicates';
  $strongarm->value = '';
  $export['media_youtube__status_display_duplicates'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__status_display_rejected';
  $strongarm->value = '';
  $export['media_youtube__status_display_rejected'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__status_display_upload_failed';
  $strongarm->value = '';
  $export['media_youtube__status_display_upload_failed'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__status_update_frequency';
  $strongarm->value = '0';
  $export['media_youtube__status_update_frequency'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__store_raw_metadata';
  $strongarm->value = 0;
  $export['media_youtube__store_raw_metadata'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_youtube__use_jw_flv';
  $strongarm->value = 0;
  $export['media_youtube__use_jw_flv'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_exhibit_audio_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => TRUE,
      'title' => 'Title',
    ),
    'body_field' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'revision_information' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'comment_settings' => array(
      'region' => 'right',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'path' => array(
      'region' => 'right',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'options' => array(
      'region' => 'right',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'author' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'buttons' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'book' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Book outline',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'field_audio' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => TRUE,
      'title' => 'Audio',
    ),
    'og_nodeapi' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Course Studios',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'print' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Printer, email and PDF versions',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'field_exhibit_reference' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'Exhibit',
    ),
  );
  $export['nodeformscols_field_placements_exhibit_audio_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_exhibit_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '-5',
      'has_required' => TRUE,
      'title' => 'Title',
    ),
    'body_field' => array(
      'region' => 'main',
      'weight' => '0.008',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'revision_information' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'comment_settings' => array(
      'region' => 'right',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'path' => array(
      'region' => 'right',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'options' => array(
      'region' => 'right',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'author' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'buttons' => array(
      'region' => 'main',
      'weight' => '100',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'book' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Book outline',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'og_nodeapi' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Course Studios',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'print' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Printer, e-mail and PDF versions',
      'collapsed' => 1,
      'hidden' => 1,
    ),
  );
  $export['nodeformscols_field_placements_exhibit_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_exhibit_image_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => TRUE,
      'title' => 'Title',
    ),
    'body_field' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'revision_information' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'comment_settings' => array(
      'region' => 'right',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'path' => array(
      'region' => 'right',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'options' => array(
      'region' => 'right',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'author' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'buttons' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'book' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Book outline',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'field_exhibit_reference' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'Exhibit',
    ),
    'field_exhibit_uimage' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => TRUE,
      'title' => 'Upload Image',
    ),
    'og_nodeapi' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Course Studios',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'print' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Printer, e-mail and PDF versions',
      'collapsed' => 1,
      'hidden' => 1,
    ),
  );
  $export['nodeformscols_field_placements_exhibit_image_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_exhibit_post_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => TRUE,
      'title' => 'Title',
    ),
    'body_field' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'revision_information' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'comment_settings' => array(
      'region' => 'right',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'path' => array(
      'region' => 'right',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'options' => array(
      'region' => 'right',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'author' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'buttons' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'book' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Book outline',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'field_exhibit_reference' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'Exhibit',
    ),
    'og_nodeapi' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Course Studios',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'print' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Printer, email and PDF versions',
      'collapsed' => 1,
      'hidden' => 1,
    ),
  );
  $export['nodeformscols_field_placements_exhibit_post_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_exhibit_video_default';
  $strongarm->value = array(
    'title' => array(
      'region' => 'main',
      'weight' => '1',
      'has_required' => TRUE,
      'title' => 'Title',
    ),
    'body_field' => array(
      'region' => 'main',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => array(
      'region' => 'right',
      'weight' => '3',
      'has_required' => FALSE,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'revision_information' => array(
      'region' => 'right',
      'weight' => '5',
      'has_required' => FALSE,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'comment_settings' => array(
      'region' => 'right',
      'weight' => '8',
      'has_required' => FALSE,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'path' => array(
      'region' => 'right',
      'weight' => '7',
      'has_required' => FALSE,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'options' => array(
      'region' => 'right',
      'weight' => '6',
      'has_required' => FALSE,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'author' => array(
      'region' => 'right',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'buttons' => array(
      'region' => 'main',
      'weight' => '4',
      'has_required' => FALSE,
      'title' => NULL,
      'hidden' => 0,
    ),
    'book' => array(
      'region' => 'right',
      'weight' => '2',
      'has_required' => FALSE,
      'title' => 'Book outline',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'field_exhibit_reference' => array(
      'region' => 'main',
      'weight' => '0',
      'has_required' => TRUE,
      'title' => 'Exhibit',
    ),
    'og_nodeapi' => array(
      'region' => 'right',
      'weight' => '1',
      'has_required' => FALSE,
      'title' => 'Course Studios',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'print' => array(
      'region' => 'right',
      'weight' => '0',
      'has_required' => FALSE,
      'title' => 'Printer, email and PDF versions',
      'collapsed' => 1,
      'hidden' => 1,
    ),
    'field_video_url' => array(
      'region' => 'main',
      'weight' => '2',
      'has_required' => TRUE,
      'title' => 'Video',
    ),
  );
  $export['nodeformscols_field_placements_exhibit_video_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_exhibit';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_exhibit_audio';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_exhibit_image';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_exhibit_post';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_exhibit_video';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_exhibit';
  $strongarm->value = 'group_post_standard';
  $export['og_content_type_usage_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_exhibit_audio';
  $strongarm->value = 'group_post_standard';
  $export['og_content_type_usage_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_exhibit_image';
  $strongarm->value = 'group_post_standard';
  $export['og_content_type_usage_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_exhibit_post';
  $strongarm->value = 'group_post_standard';
  $export['og_content_type_usage_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_exhibit_video';
  $strongarm->value = 'group_post_standard';
  $export['og_content_type_usage_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_exhibit';
  $strongarm->value = '';
  $export['og_max_groups_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_exhibit_audio';
  $strongarm->value = '';
  $export['og_max_groups_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_exhibit_image';
  $strongarm->value = '';
  $export['og_max_groups_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_exhibit_post';
  $strongarm->value = '';
  $export['og_max_groups_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_exhibit_video';
  $strongarm->value = '';
  $export['og_max_groups_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_comment_exhibit';
  $strongarm->value = 0;
  $export['print_display_comment_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_comment_exhibit_audio';
  $strongarm->value = 0;
  $export['print_display_comment_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_comment_exhibit_image';
  $strongarm->value = 0;
  $export['print_display_comment_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_comment_exhibit_post';
  $strongarm->value = 0;
  $export['print_display_comment_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_comment_exhibit_video';
  $strongarm->value = 0;
  $export['print_display_comment_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_exhibit';
  $strongarm->value = 0;
  $export['print_display_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_exhibit_audio';
  $strongarm->value = 0;
  $export['print_display_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_exhibit_image';
  $strongarm->value = 0;
  $export['print_display_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_exhibit_post';
  $strongarm->value = 0;
  $export['print_display_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_exhibit_video';
  $strongarm->value = 0;
  $export['print_display_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_urllist_exhibit';
  $strongarm->value = 0;
  $export['print_display_urllist_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_urllist_exhibit_audio';
  $strongarm->value = 0;
  $export['print_display_urllist_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_urllist_exhibit_image';
  $strongarm->value = 0;
  $export['print_display_urllist_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_urllist_exhibit_post';
  $strongarm->value = 0;
  $export['print_display_urllist_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'print_display_urllist_exhibit_video';
  $strongarm->value = 0;
  $export['print_display_urllist_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_exhibit';
  $strongarm->value = 0;
  $export['show_diff_inline_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_exhibit_audio';
  $strongarm->value = 0;
  $export['show_diff_inline_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_exhibit_image';
  $strongarm->value = 0;
  $export['show_diff_inline_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_exhibit_post';
  $strongarm->value = 0;
  $export['show_diff_inline_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_exhibit_video';
  $strongarm->value = 0;
  $export['show_diff_inline_exhibit_video'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_exhibit';
  $strongarm->value = 0;
  $export['show_preview_changes_exhibit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_exhibit_audio';
  $strongarm->value = 0;
  $export['show_preview_changes_exhibit_audio'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_exhibit_image';
  $strongarm->value = 0;
  $export['show_preview_changes_exhibit_image'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_exhibit_post';
  $strongarm->value = 0;
  $export['show_preview_changes_exhibit_post'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_exhibit_video';
  $strongarm->value = 0;
  $export['show_preview_changes_exhibit_video'] = $strongarm;

  return $export;
}
