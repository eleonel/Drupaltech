<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function elms_id_best_practices_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: admin:admin/elms/id_best_practices/settings
  $menu_links['admin:admin/elms/id_best_practices/settings'] = array(
    'menu_name' => 'admin',
    'link_path' => 'admin/elms/id_best_practices/settings',
    'router_path' => 'admin/elms/id_best_practices/settings',
    'link_title' => 'ID default settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Default settings related to instructional best practices',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'admin/elms/id_best_practices',
  );
  // Exported menu link: admin:elms_applications
  $menu_links['admin:elms_applications'] = array(
    'menu_name' => 'admin',
    'link_path' => 'elms_applications',
    'router_path' => 'elms_applications',
    'link_title' => 'List all applications',
    'options' => array(
      'purl' => 'disabled',
      'attributes' => array(
        'title' => 'Listing of all applications in the system',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'admin/elms/id_best_practices',
  );
  // Exported menu link: admin:node/add/elms-resource
  $menu_links['admin:node/add/elms-resource'] = array(
    'menu_name' => 'admin',
    'link_path' => 'node/add/elms-resource',
    'router_path' => 'node/add/elms-resource',
    'link_title' => 'Add system application',
    'options' => array(
      'purl' => 'disabled',
      'attributes' => array(
        'title' => 'Add a global resource',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'admin/elms/id_best_practices',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add system application');
  t('ID default settings');
  t('List all applications');


  return $menu_links;
}
