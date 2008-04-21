<?php
/**
 * @file
 * Functions for the handling of different barcodes
 */
/**
 * Checks to see if a valid, handalable, barcode was entered.
 * @param $barcode The Barcode to be checked
 * @return The type of barcode entered if valid, FALSE if it is not
 */
function checkBarcode($barcode) {
  /**
   * Array containinf info on the given UPC
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
}

/**
 * Output Barcode Info
 * @param $barcode The barcode to lookup
 * @return HTML code to create the info area
 * @see checkBarcode
 */
function getBarcodeInfo($barcode) {
  /**
   * Hold the HTML code to be outputted
   */
  $output = '';
  $output .= '<div id="upc">';
  $output .= '<img src="upcimg.php?upc=' . $barcode . '" />';
  $output .= '</div>';

  /**
    * Array containinf info on the given UPC
    */
  $result = XMLRPC_request('dev.upcdatabase.com', '/rpc', 'lookupUPC', array(XMLRPC_prepare($barcode)));
  /*if ($debug) */var_dump($result);
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

  return $output;
}