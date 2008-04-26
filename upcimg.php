<?php
/**
 * @brief
 * Creates an image of the barcode using Image_Barcode
 * @file
 * Uses the PHP Imagage_Barcode Extention to generate barcode images
 * for the entered barcode.  This may need to be (it can't cause any harm)
 * used in compination with pear.inc on shared hosts and other environments.
 * @see http://pear.php.net/package/Image_Barcode
 * @see http://pear.php.net/manual/en/package.images.image-barcode.php
 */
require 'include/pear.inc';
require_once 'include/barcode.inc';
require_once 'Image/Barcode.php';

if (checkBarcode($_GET['upc'])) {
  Image_Barcode::draw($_GET['upc'], checkBarcode($_GET['upc']), 'png');
}