<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function elms_navigation_top_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-usermenu:bookmarks
  $menu_links['menu-usermenu:bookmarks'] = array(
    'menu_name' => 'menu-usermenu',
    'link_path' => 'bookmarks',
    'router_path' => 'bookmarks',
    'link_title' => 'My Bookmarks',
    'options' => array(
      'purl' => 'disabled',
      'attributes' => array(
        'title' => 'My Bookmarks',
        'class' => 'menu-16504',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-usermenu:logout
  $menu_links['menu-usermenu:logout'] = array(
    'menu_name' => 'menu-usermenu',
    'link_path' => 'logout',
    'router_path' => 'logout',
    'link_title' => 'Logout',
    'options' => array(
      'purl' => 'disabled',
      'attributes' => array(
        'title' => 'Logout of ELMS',
        'class' => 'menu-16499',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-40',
  );
  // Exported menu link: menu-usermenu:parents/my
  $menu_links['menu-usermenu:parents/my'] = array(
    'menu_name' => 'menu-usermenu',
    'link_path' => 'parents/my',
    'router_path' => 'parents',
    'link_title' => 'My Courses',
    'options' => array(
      'purl' => 'disabled',
      'attributes' => array(
        'title' => 'My Courses',
        'class' => 'menu-16495',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-usermenu:user
  $menu_links['menu-usermenu:user'] = array(
    'menu_name' => 'menu-usermenu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My Profile',
    'options' => array(
      'purl' => 'disabled',
      'attributes' => array(
        'title' => 'Your User profile',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Logout');
  t('My Bookmarks');
  t('My Courses');
  t('My Profile');


  return $menu_links;
}
