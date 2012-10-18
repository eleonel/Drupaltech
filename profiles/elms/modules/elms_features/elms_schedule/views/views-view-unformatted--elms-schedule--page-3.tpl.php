<?php
// $Id: views-view-unformatted.tpl.php,v 1.6 2008/10/01 20:52:11 merlinofchaos Exp $
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */ 
 // use this to figure out the child depth for styling purposes, this has the NIDs of each row
 // create a map between the row $id and the $nid
 // then only store the values where a collapse is needed and style appropriately
  foreach($view->result as $key => $ary) {
    $tmpnid = $ary->nid;
    $depth = -1;
    //calculate depth
    while ($tmpnid != 0) {
      $last_nid = $tmpnid;
      $tmpnid = db_result(db_query("SELECT value FROM {draggableviews_structure} WHERE delta=1 AND view_name='elms_schedule' AND nid=%d", $last_nid));
      $depth++;
    }
    if ($depth == 0) {
      $nids[$key] = $ary->nid;
    }
  }
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php
  print drupal_get_form('elms_schedule_edit_form_1');
  // form all rows
  foreach ($rows as $id => $row) {
    if (isset($nids[$id])) {
        if ($id != 0) {
          print '</div><div class="schedule_container"><div class="container_close"></div><div class="schedule_heading '. $classes[$id] .'">'. $row .'</div>';
        }
        else {
          print '<div class="schedule_container"><div class="container_close"></div><div class="schedule_heading '. $classes[$id] .'">'. $row .'</div>';
        }
    }
    else {
      print '<div class="schedule_row '. $classes[$id] .'">'. $row .'</div>';
    }
  }
?>
</div>