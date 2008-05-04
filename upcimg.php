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
 *
 * @bug
 * Doesn't draw images anymore, must figure out why
 */
require_once 'include/pear.inc';
require_once 'include/barcode.inc';
require_once 'Image/Barcode.php';

// Disable non-fatal errors
error_reporting(E_ERROR);

if (checkBarcode($_GET['upc'])) {
  Image_Barcode::draw($_GET['upc'], checkBarcode($_GET['upc']), 'png');
}