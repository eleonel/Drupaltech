<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function elms_open_studio_menu_default_menu_links() {
  $menu_links = array();
  // Exported menu link: features:open_studio
  $menu_links['features:open_studio'] = array(
    'menu_name' => 'features',
    'link_path' => 'open_studio',
    'router_path' => 'open_studio',
    'link_title' => 'Studio Gallery',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: features:open_studio/my
  $menu_links['features:open_studio/my'] = array(
    'menu_name' => 'features',
    'link_path' => 'open_studio/my',
    'router_path' => 'open_studio/my',
    'link_title' => 'My Gallery',
    'options' => array(
      'attributes' => array(
        'title' => 'A listing of all your exhibits for the studio',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-usermenu:my_studio
  $menu_links['menu-usermenu:my_studio'] = array(
    'menu_name' => 'menu-usermenu',
    'link_path' => 'my_studio',
    'router_path' => 'my_studio',
    'link_title' => 'My Exhibits',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add post / media');
  t('Create Exhibit');
  t('My Exhibits');
  t('My Gallery');
  t('Studio Gallery');


  return $menu_links;
}
