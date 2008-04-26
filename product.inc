<?php
/**
 * @file Functions to output Product Info
 */
require_once 'utils.inc';
/**
 * Gets Appropriate Images from google Image Search
 * @param $product The product to get images for
 * @return HTML code to output product images
 */
function getImages($product) {
  /**
   * Holds an array conatining the results of the search
   */
  $json = json_decode(fget('http://ajax.googleapis.com/ajax/services/search/images?v=1.0&q=' . urlencode($product)));
  var_dump($json);
  /**
   * The code to be outputed
   */
  $output = '';
  return $output;
}