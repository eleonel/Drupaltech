<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function elms_site_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_section_info
  $groups['site-group_section_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'site',
    'group_name' => 'group_section_info',
    'label' => 'Section Info',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-1',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-1',
    'fields' => array(
      '0' => 'field_section_semester',
      '1' => 'field_section_year',
      '2' => 'field_campus',
      '3' => 'field_section_number',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Section Info');

  return $groups;
}
