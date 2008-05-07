<?php
/**
 * @brief
 * Functions for the handling of different barcodes
 * @file
 * This file currently deals with the handling of barcodes and getting the information associated with them.
 */
require_once 'pear.inc';
require_once 'xmlrpc.inc';
require_once 'product.inc';
require_once 'xmlparse.inc';
/**
 * Checks to see if a valid, handalable, barcode was entered.
 * @param $barcode The Barcode to be checked
 * @param $type = The type of barcode, either "upc" or "isbn". Defaults to
 * what is passed in the HTTP GET information if available, otherwise
 * assumes "upc".
 * @return The type of barcode entered if valid, FALSE if it is not
 */
function checkBarcode($barcode, $type = 'upc') {
  if (isset($_GET['type'])) {
    $type = $_GET['type'];
  }

  switch ($type) {
    case 'upc':
      /**
      * Array containing info on the given UPC
      */
      $result = XMLRPC_request('dev.upcdatabase.com', '/rpc', 'lookupUPC', array(XMLRPC_prepare($barcode)));
      if ($result[1] != 'Error: Invalid length') {
        if (strlen($barcode) == 12) {
          return 'upca';
        }
        else if (strlen($barcode) == 13) {
          return 'ean13';
        }
        else {
          return FALSE;
        }
      }
      else {
        return FALSE;
      }
      break;
    case 'isbn':
      if (strlen($barcode) == 10) {
        return 'isbn';
      }
      else if (strlen($barcode) == 13) {
        return 'bookland';
      }
      else {
        return FALSE;
      }
      break;
  }
}

/**
 * Output Barcode Info
 * @param $barcode The barcode to lookup
 * @return HTML code to create the info area
 * @see checkBarcode
 */
function getBarcodeInfo($barcode) {
  switch ($_GET['type']) {
    case 'upc':
      /**
      * Hold the HTML code to be outputted
      */
      $output = '';
      $output .= '<div id="upc">';
      $output .= '<img src="upcimg.php?upc=' . $barcode . '" />';
      $output .= '</div>';

      /**
      * Array containing info on the given UPC
      */
      $result = XMLRPC_request('dev.upcdatabase.com', '/rpc', 'lookupUPC', array(XMLRPC_prepare($barcode)));
//       if ($debug) var_dump($result);
      echo getImages($result[1]['description']);
      if ($result[1]['found']) {
        extract($result[1], EXTR_PREFIX_ALL, 'barcode');
        $output .= <<<_HTML
        <div id="info">
          <table align="center">
            <tr>
              <td class="title">Country</td>
              <td>$barcode_issuerCountry</td>
            </tr>
            <tr>
              <td class="title">Description</td>
              <td>$barcode_description</td>
            </tr>
            <tr>
              <td class="title">Size</td>
              <td>$barcode_size</td>
            </tr>
          </table>
          <a href="http://www.upcdatabase.com/editform.asp?upc=$barcode">Modify this entry</a>
          <a href="http://www.upcdatabase.com/deleteform.asp?upc=$barcode">Delete this entry</a>
        </div>
_HTML;
      }
      else {
        $output .= 'Product Not Found!<br />';
        $output .= '<a href="http://www.upcdatabase.com/addform.asp?upc=' . $barcode . '">Add this item to the database</a>';
      }
      break;

    case 'isbn':
      /**
       * Object containing parsed XML data
       */
      $xml = parseXML('http://isbndb.com/api/books.xml?access_key=' . ISBNKEY . '&index1=isbn&results=texts&value1=' . $barcode);
//       var_dump($xml);

      // Sometimes, the long title is non-existant, so fall back onto the short title
      if (strlen($xml->BookList->BookData->TitleLong) != 0) {
        /**
         * Book Title
         */
        $title = $xml->BookList->BookData->TitleLong;
      }
      else {
        /**
         * Book Title
         */
        $title = $xml->BookList->BookData->Title;
      }
      /**
       * Book Author
       */
      $author = $xml->BookList->BookData->AuthorsText;
      /**
       * Book Publisher
       */
      $publisher = $xml->BookList->BookData->PublisherText;
      /**
       * Book Summary
       */
      $summary = $xml->BookList->BookData->Summary;
      /**
       * ISBN-10 Code
       */
      $isbn = $xml->BookList->BookData['isbn'];

      /**
      * Hold the HTML code to be outputted
      */
      $output = '';
      $output .= '<div id="upc">';
      $output .= '<img src="upcimg.php?upc=' . $barcode . '" />';
      $output .= '</div>';
      $output .= <<<_HTML
      <div id="info">
        <table align="center">
          <tr>
            <td class="title">Title</td>
            <td>$title</td>
          </tr>
          <tr>
            <td class="title">Author</td>
            <td>$author</td>
          </tr>
          <tr>
            <td class="title">Publisher</td>
            <td>$publisher</td>
          </tr>
          <tr>
            <td colspan="2">$summary</td>
          </tr>
          <tr>
            <td class="title">Buy</td>
            <td>
              <!-- Amazon.com uses the ISBN-10 code, so send it that -->
              <a href="http://www.amazon.com/exec/obidos/ASIN/$isbn/">Amazon.com</a><br />
              <!-- Everyone else uses the ISBN-13 code, so send them that -->
              <a href="http://search.barnesandnoble.com/booksearch/isbninquiry.asp?ean=$barcode">Barnes & Noble</a><br />
              <a href="http://www.booksamillion.com/ncom/books?type=isbn&find=$barcode">Books-A-Million</a><br />
              <a href="http://www.google.com/products?q=$barcode">Google Product Search</a>
            </td>
          </tr>
        </table>
      </div>
_HTML;
      break;
  }

  return $output;
}