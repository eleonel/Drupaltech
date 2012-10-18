<?php

/**
 * Implementation of hook_content_default_fields().
 */
function elms_site_content_default_fields() {
  $fields = array();

  // Exported field: field_campus
  $fields['site-field_campus'] = array(
    'field_name' => 'field_campus',
    'type_name' => 'site',
    'display_settings' => array(
      'weight' => '20',
      'parent' => 'group_section_info',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'oz|Abington Campus
aa|Altoona Campus
br|Beaver Campus
bk|Berks Campus
de|Brandywine Campus
dn|Dickinson School of Law
ds|Dubois Campus
fe|Fayette Campus
xs|Foreign Studies Program
mk|Greater Allegheny Campus
hn|Hazleton Campus
an|Lehigh Valley Campus
hy|Milton S. Hershey Medical Center
ma|Mont Alto Campus
nk|New Kensington Campus
bd|Penn State Erie, The Behrend College
kp|Penn State Great Valley
cl|Penn State Harrisburg, The Capital College
sl|Schuylkill Campus
sv|Shenango Campus
up|University Park
wb|Wilkes-Barre Campus
wd|World Campus
ws|Worthington Scranton Campus
yk|York Campus',
    'allowed_values_php' => '',
    'widget' => array(
      'multistep' => '6',
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Campus',
      'weight' => '20',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_parent_ref
  $fields['site-field_parent_ref'] = array(
    'field_name' => 'field_parent_ref',
    'type_name' => 'site',
    'display_settings' => array(
      'weight' => '-5',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'parent' => 'parent',
      'accessibility_guideline' => 0,
      'accessibility_test' => 0,
      'content_links' => 0,
      'elms_resource' => 0,
      'page' => 0,
      'place' => 0,
      'poll' => 0,
      'referenced_page' => 0,
      'term' => 0,
      'timeline_item' => 0,
      'site' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 0,
        'title' => 'Site',
        'hover_title' => '',
        'destination' => 'default',
      ),
      'fallback' => 'select',
      'edit_fallback' => 0,
      'autocomplete_match' => 'contains',
      'size' => '20',
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Parent',
      'weight' => '-5',
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_section_number
  $fields['site-field_section_number'] = array(
    'field_name' => 'field_section_number',
    'type_name' => 'site',
    'display_settings' => array(
      'weight' => '21',
      'parent' => 'group_section_info',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '3',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '3',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_section_number][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Section Number',
      'weight' => '21',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_section_semester
  $fields['site-field_section_semester'] = array(
    'field_name' => 'field_section_semester',
    'type_name' => 'site',
    'display_settings' => array(
      'weight' => '18',
      'parent' => 'group_section_info',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'active|Active
fa|Fall
sp|Spring
su|Summer
su1|Summer 1
su2|Summer 2',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 'active',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Section Semester',
      'weight' => '18',
      'description' => 'Select the semester that this is associated to. If you only want to have 1 active section at a time, use active which will create a path with _active in it.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_section_year
  $fields['site-field_section_year'] = array(
    'field_name' => 'field_section_year',
    'type_name' => 'site',
    'display_settings' => array(
      'weight' => '19',
      'parent' => 'group_section_info',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '201112|201112
201213|201213
201314|201314
201415|201415
201516|201516
201617|201617
201718|201718',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Year',
      'weight' => '19',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Campus');
  t('Parent');
  t('Section Number');
  t('Section Semester');
  t('Year');

  return $fields;
}
