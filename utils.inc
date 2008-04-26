<?php
/**
 * @file Helpful Utilities
 */
/**
 * Download a @b text file using cURL
 * @param The URL to download
 * @return A string containging the text file
 */
function fget($url) {
  /**
   * Holds the cURL resource for use in other cURL related functions
   */
  $curl = curl_init($url);
  $options = array(
    CURLOPT_REFERER => $_ENV['SCRIPT_URI'],
    CURLOPT_FAILONERROR => TRUE,
    CURLOPT_RETURNTRANSFER => 1,
    CURLOPT_CLOSEPOLICY => CURLCLOSEPOLICY_LEAST_RECENTLY_USED,
  );
  /**
   * Contains the file that was just downloaded
   */
  $file = curl_exec($curl);
  curl_close($curl);

  return $file;
}