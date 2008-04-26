<?php
/**
 * @brief
 * Main handler file, contains all HTML code
 * @file
 * This is the main output file, the file that calls all other functions.
 * This file should not need to be modified very often.
 */
require 'include/pear.inc';
require_once 'include/xmlrpc.inc';
require_once 'include/form.inc';
require_once 'include/barcode.inc';
require_once 'include/product.inc';

/**
 * Set to TRUE to output debug info
 */
$debug = TRUE;
/**
 * The Google AJAX search API key
 * @see http://code.google.com/apis/ajaxsearch/signup.html
 */
define('APIKEY', 'ABQIAAAAEmJBx7wui2me6l65B9cbGxSgpExuB0qMRQJK1CqbTmGBEUmrHxTWS-jq0HtIRjmBHjux30WT0zQnaQ');
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <meta http-equiv="Content-Type" content=
  "text/html; charset=us-ascii" />
  <meta name="Language" content="English" />

  <!-- Styles -->
  <link type="text/css" rel="stylesheet" href="style.css" />
  <link type="text/css" rel="stylesheet" href="form.css" />

  <title>UPC Lookup</title>
</head>

<body>
  <div id="container">
    <a href="index.php"><div class="mainimage"></div></a>

    <div id="menu">
      <div id="plug">Uses the <a href="http://www.upcdatabase.com/">UPC Database</a></div>
<!--      <ul>
        <li><a href="#" title="Home">Home</a></li>

        <li><a href="#" title="News">News</a></li>

        <li><a href="#" title="About">About</a></li>

        <li><a href="#" title="Gallery">Gallery</a></li>

        <li><a href="#" title="Links">Links</a></li>

        <li><a href="#" title="Contact">Contact</a></li>
      </ul>-->
    </div>

    <div id="bodytext">
      <?php
        /**
         * Holds the barcode entered
         * @note Can hold any barcode, but named $upc for ease of entry
         */
        $upc = $_GET['upc'];
        if ($upc) {
          if (checkBarcode($upc)) {
            echo getBarcodeInfo($upc);
          }
          else {
            echo <<<_HTML
            <div id="info" class="error">
              The barcode with the value $upc is not valid.
            </div>
_HTML;
          }
        }
        echo getEntryForm();
      ?>
    </div>
  </div>

  <div class="footer">
    <div class="right">
      Designed By <a href="http://www.christinachun.com" title=
      "Christina Chun - Digital Artist &amp; Web Developer">Christina
      Chun</a> &copy; 2005-2006 | <a href="http://www.owsd.org"
      title="Open Source Web Design">Open Source Web Design</a> |
      <a href="http://validator.w3.org/check?uri=referer">Valid
      XHTML</a>
    </div>
  </div>
</body>
</html>
