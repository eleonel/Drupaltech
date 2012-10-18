<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function elms_open_studio_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => 2);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function elms_open_studio_imagecache_default_presets() {
  $items = array(
    'Saved size' => array(
      'presetname' => 'Saved size',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecrop',
          'action' => 'imagecrop_javascript',
          'data' => array(
            'width' => '100%',
            'height' => '100%',
            'xoffset' => '',
            'yoffset' => '',
            'resizable' => 1,
            'aspect' => FALSE,
            'disable_if_no_data' => 1,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '70%',
            'height' => '70%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'gallery_size' => array(
      'presetname' => 'gallery_size',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '200',
            'height' => '200',
          ),
        ),
      ),
    ),
    'micro' => array(
      'presetname' => 'micro',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '400',
            'height' => '400',
            'upscale' => 1,
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '200',
            'height' => '200',
            'xoffset' => 'center',
            'yoffset' => 'center',
          ),
        ),
        '2' => array(
          'weight' => '-8',
          'module' => 'imagecache',
          'action' => 'imagecache_resize',
          'data' => array(
            'width' => '65',
            'height' => '65',
          ),
        ),
      ),
    ),
    'overview_thumb' => array(
      'presetname' => 'overview_thumb',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '300',
            'height' => '300',
            'upscale' => 1,
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '125',
            'height' => '125',
            'xoffset' => 'center',
            'yoffset' => '50',
          ),
        ),
        '2' => array(
          'weight' => '-8',
          'module' => 'imagecache_coloractions',
          'action' => 'imagecache_convert',
          'data' => array(
            'format' => 'image/png',
          ),
        ),
        '3' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_roundedcorners',
          'data' => array(
            'radius' => '4',
            'independent_corners_set' => array(
              'independent_corners' => 0,
              'radii' => array(
                'tl' => '',
                'tr' => '',
                'bl' => '',
                'br' => '',
              ),
            ),
            'antialias' => TRUE,
          ),
        ),
      ),
    ),
    'overview_thumb_gray' => array(
      'presetname' => 'overview_thumb_gray',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '300',
            'height' => '300',
            'upscale' => 1,
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '125',
            'height' => '125',
            'xoffset' => 'center',
            'yoffset' => '50',
          ),
        ),
        '2' => array(
          'weight' => '-7',
          'module' => 'imagecache',
          'action' => 'imagecache_desaturate',
          'data' => array(),
        ),
        '3' => array(
          'weight' => '-6',
          'module' => 'imagecache_coloractions',
          'action' => 'imagecache_convert',
          'data' => array(
            'format' => 'image/png',
          ),
        ),
        '4' => array(
          'weight' => '-5',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_roundedcorners',
          'data' => array(
            'radius' => '4',
            'independent_corners_set' => array(
              'independent_corners' => 0,
              'radii' => array(
                'tl' => '',
                'tr' => '',
                'bl' => '',
                'br' => '',
              ),
            ),
            'antialias' => TRUE,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function elms_open_studio_node_info() {
  $items = array(
    'exhibit' => array(
      'name' => t('Exhibit'),
      'module' => 'features',
      'description' => t('Use this to organize your work'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'exhibit_audio' => array(
      'name' => t('Exhibit audio'),
      'module' => 'features',
      'description' => t('Embed audio from external sources'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'exhibit_image' => array(
      'name' => t('Exhibit image'),
      'module' => 'features',
      'description' => t('Use this to add an image to your exhibit'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'exhibit_post' => array(
      'name' => t('Exhibit post'),
      'module' => 'features',
      'description' => t('A post to the open studio without media.  Use this for blog posts and other written assignments.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'exhibit_video' => array(
      'name' => t('Exhibit video'),
      'module' => 'features',
      'description' => t('Add a video to your exhibit from an external source'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function elms_open_studio_views_api() {
  return array(
    'api' => '2',
  );
}
