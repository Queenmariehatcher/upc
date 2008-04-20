<?php
/**
 * @file
 * Makes PEAR work with extentions installed in the home directory.
 */
set_include_path(get_include_path() . PATH_SEPARATOR . '/home/dkeenan/pear/php');