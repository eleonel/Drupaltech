<?php

/**
 * @file
 * Download via HTTP.
 *
 * Support caching, HTTP Basic Authentication, detection of RSS/Atom feeds,
 * redirects.
 */

/**
 * PCRE for finding the link tags in html.
 */
define('HTTP_REQUEST_PCRE_LINK_TAG', '/<link((?:[\x09\x0A\x0B\x0C\x0D\x20]+[^\x09\x0A\x0B\x0C\x0D\x20\x2F\x3E][^\x09\x0A\x0B\x0C\x0D\x20\x2F\x3D\x3E]*(?:[\x09\x0A\x0B\x0C\x0D\x20]*=[\x09\x0A\x0B\x0C\x0D\x20]*(?:"(?:[^"]*)"|\'(?:[^\']*)\'|(?:[^\x09\x0A\x0B\x0C\x0D\x20\x22\x27\x3E][^\x09\x0A\x0B\x0C\x0D\x20\x3E]*)?))?)*)[\x09\x0A\x0B\x0C\x0D\x20]*(>(.*)<\/link>|(\/)?>)/si');

/**
 * PCRE for matching all the attributes in a tag.
 */
define('HTTP_REQUEST_PCRE_TAG_ATTRIBUTES', '/[\x09\x0A\x0B\x0C\x0D\x20]+([^\x09\x0A\x0B\x0C\x0D\x20\x2F\x3E][^\x09\x0A\x0B\x0C\x0D\x20\x2F\x3D\x3E]*)(?:[\x09\x0A\x0B\x0C\x0D\x20]*=[\x09\x0A\x0B\x0C\x0D\x20]*(?:"([^"]*)"|\'([^\']*)\'|([^\x09\x0A\x0B\x0C\x0D\x20\x22\x27\x3E][^\x09\x0A\x0B\x0C\x0D\x20\x3E]*)?))?/');

/**
 * For cUrl specific errors.
 */
class HRCurlException extends Exception {}

/**
 * Discover RSS or atom feeds at the given URL. If document in given URL is an
 * HTML document, function attempts to discover RSS or Atom feeds.
 *
 * @return
 *  string - the discovered feed, FALSE - if the URL is not reachable or there
 *    no feeds.
 */
function http_request_get_common_syndication($url, $settings = NULL) {
  $password = $username = NULL;
  if (feeds_valid_url($url, TRUE)) {
    // Handle password protected feeds.
    $url_parts = parse_url($url);
    if (!empty($url_parts['user'])) {
      $password = $url_parts['pass'];
      $username = $url_parts['user'];
    }
  }

  $accept_invalid_cert = isset($settings['accept_invalid_cert']) ? $settings['accept_invalid_cert'] : TRUE;
  $download = http_request_get($url, $username, $password, $accept_invalid_cert);

  // Cannot get the feed, return.
  // http_request_get() always returns 200 even if its 304.
  if ($download->code != 200) {
    return FALSE;
  }

  // Drop the data into a seperate variable so all manipulations of the html
  // will not effect the actual object that exists in the static cache.
  // @see http_request_get.
  $downloaded_string = $download->data;
  // If this happens to be a feed then just return the url.
  if (http_request_is_feed($download->headers['Content-Type'], $downloaded_string)) {
    return $url;
  }

  $discovered_feeds = http_request_find_feeds($downloaded_string);
  foreach ($discovered_feeds as $feed_url) {
    $absolute = http_request_create_absolute_url($feed_url, $url);
    if (!empty($absolute)) {
      // @TODO: something more intelligent?
      return $absolute;
    }
  }
}

/**
 * Get the content from the given URL.
 *
 * @param $url
 *  A valid URL (not only web URLs).
 * @param $username
 *  If the URL use authentication, here you can supply the username for this.
 * @param $password
 *  If the URL use authentication, here you can supply the password for this.
 * @return
 *  A stdClass object that describes the data downloaded from $url. The object's
 *  data property contains the actual document at the URL.
 */
function http_request_get($url, $username = NULL, $password = NULL, $accept_invalid_cert = TRUE) {
  // Intra-pagedownload cache, avoid to download the same content twice within one page download (it's possible, compatible and parse calls).
  static $download_cache = array();
  if (isset($download_cache[$url])) {
    return $download_cache[$url];
  }
  $has_etag = FALSE;
  $curl = http_request_use_curl();

  // Only download and parse data if really needs refresh.
  // Based on "Last-Modified" and "If-Modified-Since".
  $headers = array();
  if ($cache = cache_get('feeds_http_download_'. md5($url))) {
    $last_result = $cache->data;
    $last_headers = $last_result->headers;

    $has_etag = TRUE;
    if (!empty($last_headers['ETag'])) {
      if ($curl) {
        $headers[] = 'If-None-Match: '. $last_headers['ETag'];
      }
      else {
        $headers['If-None-Match'] = $last_headers['ETag'];
      }
    }
    if (!empty($last_headers['Last-Modified'])) {
      if ($curl) {
        $headers[] = 'If-Modified-Since: '. $last_headers['Last-Modified'];
      }
      else {
        $headers['If-Modified-Since'] = $last_headers['Last-Modified'];
      }
    }
    if (!empty($username) && !$curl) {
      $headers['Authorization'] = 'Basic '. base64_encode("$username:$password");
    }
  }

  // Support the 'feed' and 'webcal' schemes by converting them into 'http'.
  $url = strtr($url, array('feed://' => 'http://', 'webcal://' => 'http://'));

  if ($curl) {
    $headers[] = 'User-Agent: Drupal (+http://drupal.org/)';
    $result = new stdClass();

    // Parse the URL and make sure we can handle the schema.
    // cURL can only support either http:// or https://.
    // CURLOPT_PROTOCOLS is only supported with cURL 7.19.4
    $uri = parse_url($url);
    if (!isset($uri['scheme'])) {
      $result->error = 'missing schema';
      $result->code = -1002;
    }
    else {
      switch ($uri['scheme']) {
        case 'http':
        case 'https':
          // Valid scheme.
          break;
        default:
          $result->error = 'invalid schema ' . $uri['scheme'];
          $result->code = -1003;
          break;
      }
    }

    // If the scheme was valid, continue to request the feed using cURL.
    if (empty($result->error)) {
      $download = curl_init($url);
      curl_setopt($download, CURLOPT_FOLLOWLOCATION, TRUE);
      if (!empty($username)) {
        curl_setopt($download, CURLOPT_USERPWD, "{$username}:{$password}");
      }
      curl_setopt($download, CURLOPT_HTTPHEADER, $headers);
      curl_setopt($download, CURLOPT_HEADER, TRUE);
      curl_setopt($download, CURLOPT_RETURNTRANSFER, TRUE);
      curl_setopt($download, CURLOPT_ENCODING, '');
      curl_setopt($download, CURLOPT_TIMEOUT, variable_get('http_request_timeout', 15));
      if ($accept_invalid_cert) {
        curl_setopt($download, CURLOPT_SSL_VERIFYPEER, FALSE);
      }
      $header = '';
      $data = curl_exec($download);
      if (curl_error($download)) {
        throw new HRCurlException(t('cURL error (@code) @error for @url', array('@code' => curl_errno($download), '@error' => curl_error($download), '@url' => $url)), curl_errno($download));
      }
      $header_size = curl_getinfo($download, CURLINFO_HEADER_SIZE);
      $header = substr($data, 0, $header_size - 1);
      $result->data = substr($data, $header_size);
      $header_lines = preg_split("/\r\n|\n|\r/", $header);

      $result->headers = array();
      array_shift($header_lines); // skip HTTP response status
      while ($line = trim(array_shift($header_lines))) {
        list($header, $value) = explode(':', $line, 2);
        if (isset($result->headers[$header]) && $header == 'Set-Cookie') {
          // RFC 2109: the Set-Cookie response header comprises the token Set-
          // Cookie:, followed by a comma-separated list of one or more cookies.
          $result->headers[$header] .= ','. trim($value);
        }
        else {
          $result->headers[$header] = trim($value);
        }
      }
      $result->code = curl_getinfo($download, CURLINFO_HTTP_CODE);

      curl_close($download);
    }
  }
  else {
    $result = drupal_http_request($url, $headers);
  }

  $result->code = isset($result->code) ? $result->code : 200;

  // In case of 304 Not Modified try to return cached data.
  if ($result->code == 304) {

    if (isset($last_result)) {
      $last_result->from_cache = TRUE;
      return $last_result;
    }
    else {
      // It's a tragedy, this file must exist and contain good data.
      // In this case, clear cache and repeat.
      cache_clear_all('feeds_http_download_'. md5($url), 'cache');
      return http_request_get($url, $username, $password);
    }
  }

  if (!isset($result->headers) || !isset($result->headers['ETag']) || !isset($result->headers['Last-Modified'])) {
    $result->headers = isset($result->headers) ? $result->headers : array();
    $result->headers['ETag'] = isset($result->headers['ETag']) ? $result->headers['ETag'] : '';
    $result->headers['Last-Modified'] = isset($result->headers['Last-Modified']) ? $result->headers['Last-Modified'] : '';
  }

  // Set caches.
  cache_set('feeds_http_download_'. md5($url), $result);
  $download_cache[$url] = $result;

  return $result;
}

/**
 * Decides if it's possible to use cURL or not.
 *
 * @return
 *   TRUE if curl is available, FALSE otherwise.
 */
function http_request_use_curl() {
  // Allow site administrators to choose to not use cURL.
  if (variable_get('feeds_never_use_curl', FALSE)) {
    return FALSE;
  }

  // Check availability of cURL on the system.
  $basedir = ini_get("open_basedir");
  return function_exists('curl_init') && !ini_get('safe_mode') && empty($basedir);
}

/**
 * Clear cache for a specific URL.
 */
function http_request_clear_cache($url) {
  cache_clear_all('feeds_http_download_'. md5($url), 'cache');
}

/**
 * Returns if the provided $content_type is a feed.
 *
 * @param string $content_type
 *  The Content-Type header.
 *
 * @param string $data
 *  The actual data from the http request.
 *
 * @return boolean
 *  Returns TRUE if this is a parsable feed.
 */
function http_request_is_feed($content_type, $data) {
  $pos = strpos($content_type, ';');
  if ($pos !== FALSE) {
    $content_type = substr($content_type, 0, $pos);
  }
  $content_type = strtolower($content_type);
  if (strpos($content_type, 'xml') !== FALSE) {
    return TRUE;
  }

  // @TODO: Sometimes the content-type can be text/html but still be a valid
  // feed.
  return FALSE;
}

/**
 * Finds potential feed tags in the HTML document.
 *
 * @param string $html
 *  The html string to search.
 *
 * @return array()
 *  An array of href to feeds.
 */
function http_request_find_feeds($html) {
  $matches = array();
  preg_match_all(HTTP_REQUEST_PCRE_LINK_TAG, $html, $matches);
  $links = $matches[1];
  $candidates = array();
  $valid_links = array();

  // Build up all the links information.
  foreach ($links as $link_tag) {
    $attributes = array();
    $candidate = array();

    preg_match_all(HTTP_REQUEST_PCRE_TAG_ATTRIBUTES, $link_tag, $attributes, PREG_SET_ORDER);
    foreach ($attributes as $attribute) {
      // Find the key value pairs, attribute[1] is key and attribute[2] is the
      // value.
      if (!empty($attribute[1]) && !empty($attribute[2])) {
        $candidate[drupal_strtolower($attribute[1])] = drupal_strtolower(decode_entities($attribute[2]));
      }
    }

    // Examine candidate to see if it s a feed.
    // @TODO: could/should use http_request_is_feed ??
    if (isset($candidate['rel']) && $candidate['rel'] == 'alternate') {
      if (isset($candidate['href']) && isset($candidate['type']) && strpos($candidate['type'], 'xml') !== FALSE) {
        // All tests pass, its a valid candidate.
        $valid_links[] = $candidate['href'];
      }
    }
  }

  return $valid_links;
}

/**
 * Create an absolute url.
 *
 * @param string $url
 *  The href to transform.
 *
 * @param $base_url
 *  The url to be used as the base for a relative $url.
 *
 * @return string
 *  an absolute url
 */
function http_request_create_absolute_url($url, $base_url) {
  $url = trim($url);
  if (valid_url($url, TRUE)) {
    // Valid absolute url already.
    return $url;
  }

  // Turn relative url into absolute.
  if (valid_url($url, FALSE)) {
    // Produces variables $scheme, $host, $user, $pass, $path, $query and $fragment.
    $parsed_url = parse_url($base_url);

    $path = dirname($parsed_url['path']);

    // Adding to the existing path.
    if ($url{0} == '/') {
      $cparts = array_filter(explode("/", $url));
    }
    else {
      // Backtracking from the existing path.
      $cparts = array_merge(array_filter(explode("/", $path)), array_filter(explode("/", $url)));
      foreach ($cparts as $i => $part) {
        if ($part == '.') {
          $cparts[$i] = NULL;
        }
        if ($part == '..') {
          $cparts[$i - 1] = NULL;
          $cparts[$i] = NULL;
        }
      }
      $cparts = array_filter($cparts);
    }
    $path = implode("/", $cparts);

    // Build the prefix to the path.
    $absolute_url = '';
    if (isset($parsed_url['scheme'])) {
      $absolute_url = $parsed_url['scheme'] . '://';
    }

    if (isset($parsed_url['user'])) {
      $absolute_url .= $parsed_url['user'];
      if (isset($pass)) {
        $absolute_url .= ':' . $parsed_url['pass'];
      }
      $absolute_url .= '@';
    }
    if (isset($parsed_url['host'])) {
      $absolute_url .= $parsed_url['host'] . '/';
    }

    $absolute_url .= $path;

    if (valid_url($absolute_url, TRUE)) {
      return $absolute_url;
    }
  }
  return FALSE;
}
