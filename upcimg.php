<?php
/**
 * @file
 * Creates an image of the barcode using Image_Barcode
 * @see http://pear.php.net/package/Image_Barcode
 * @see http://pear.php.net/manual/en/package.images.image-barcode.php
 */
include('pear.inc');
require_once 'Image/Barcode.php';
Image_Barcode::draw($_GET['upc'], 'upca', 'png');