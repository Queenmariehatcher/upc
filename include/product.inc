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
 * @todo Make images more accurate
 * @todo Add left and right arrows to choose image to show
 */
function getImages($product) {
  /**
   * Object conatining the results of the search
   */
  $json = json_decode(fget('http://ajax.googleapis.com/ajax/services/search/images?v=1.0&q=' . urlencode($product)));
  /**
   * URL of the resized image
   */
  $imgpath = $json->responseData->results[0]->tbUrl;
  /**
   * Image Source Domain (i.e. bestbuy.com)
   */
  $imgsource = $json->responseData->results[0]->visibleUrl;
  /**
   * Image Source URL
   */
  $imgsourceurl = $json->responseData->results[0]->tbUrl;
  /**
   * Original Image Context
   */
  $imgcontext = $json->responseData->results[0]->originalContextUrl;
  /**
   * The code to be outputed
   */
  $output = '';
  $output = <<<_HTML
    <div id="prodimg">
      <a href="$imgcontext" target="_blank">
        <img src="$imgpath" alt="Image of $product From $imgsource" title="Image of $product From $imgsource">
      </a><br />
      <a href="aboutimages.html" target="_blank" onclick="popup(this.href, 200, 300); return false;">About this image</a>
    </div>
_HTML;

  return $output;
}
