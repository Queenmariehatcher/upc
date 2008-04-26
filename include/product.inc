<?php
/**
 * @brief
 * Functions to output Product Info
 * @file
 * Various pieces of info gleamed from the web will be handled by functions
 * contained in this file. Currently, it only handles getting product images
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