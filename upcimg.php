<?php
/**
 * @file
 * Creates an image of the barcode using Image_Barcode
 * @see http://pear.php.net/package/Image_Barcode
 * @see http://pear.php.net/manual/en/package.images.image-barcode.php
 */
require 'pear.inc';
require_once 'barcode.inc';
require_once 'Image/Barcode.php';

if (checkBarcode($_GET['upc'])) {
  Image_Barcode::draw($_GET['upc'], checkBarcode($_GET['upc']), 'png');
}