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
 * @param $type The Product type to search for, defaults to a generic product. If
 * it is a book, "book" is appended to the search query to narrow the result to
 * what should be book covers.
 * @return HTML code to output product images
 */
function getImages($product, $type = 'generic') {
  /**
   * Holds the Search Query
   */
  $q = '';
  switch ($type) {
    case 'generic':
      $q = urlencode("\"$product\"");
      break;
    case 'book':
      $q = urlencode("\"$product\" book");
      break;
  }
  /**
   * Object conatining the results of the search
   */
  $json = json_decode(fget('http://ajax.googleapis.com/ajax/services/search/images?v=1.0&q=' . $q . '&rsz=large'));

  // Hack to get Indexes working
  if ($_GET['index']) {
    $currentIndex = (int) $_GET['index'];
  }
  else {
    $currentIndex = 0;
  }
  $prevIndex = $currentIndex - 1;
  $nextIndex = $currentIndex + 1;
  $i = 0;
  $getText = '?';
  foreach ($_GET as $item) {
    if (key($_GET) != 'index') {
      if ($i == 0) {
        $getText .= key($_GET) . '=' . $item;
      }
      else {
        $getText .= '&' . key($_GET) . '=' . $item;
      }
    }
    next($_GET);
    $i++;
  }

  $originalContextUrl = $json->responseData->results[$currentIndex]->originalContextUrl;
  $imgSrc = $json->responseData->results[$currentIndex]->tbUrl;
  $visibleUrl = $json->responseData->results[$currentIndex]->visibleUrl;

  /**
   * The code to be outputed
   */
  $output = "<div id=\"prodimg\">";
  // Only display previous button if there are previous values
  if ($currentIndex > 0) {
    $output .= "<a href=\"{$getText}&index={$prevIndex}\"><img src=\"images/arrows/left.png\" alt=\"Previous Image\" title=\"Previous Image\" /></a>";
  }
  $output .= "<a href=\"{$originalContextUrl}\" target=\"_blank\"><img src=\"{$imgSrc}\" alt=\"Image of $product From {$visibleUrl}\" title=\"Image of $product From {$visibleUrl}\" id=\"prodimg\"></a>";
  // Only display next button if there are more images
  if ($currentIndex < count($json->responseData->results) - 1) {
   $output .= "<a href=\"{$getText}&index={$nextIndex}\"> <img src=\"images/arrows/right.png\" alt=\"Next Image\" title=\"Next Image\" /></a><br /><a href=\"aboutimages.html\" target=\"_blank\" onclick=\"popup(this.href, 200, 300); return false;\">About this image</a></div>";
  }

  return $output;
}
