<?php
/**
 * @file
 * Enable clones of book and menu items to be joined correctly
 */

/**
 * Implements hook_spaces_og_clone_node_query().
 */
function book_spaces_og_clone_node_query(&$query, $new_group, $old_group, $settings) {
  $query['joins']['book'] = "LEFT JOIN {book} as b ON b.nid = n.nid ";
  $query['joins']['menu_links'] = "LEFT JOIN {menu_links} as ml ON ml.mlid = b.mlid ";
  $query['order']['menu_links'] = "ml.depth ASC";
}
