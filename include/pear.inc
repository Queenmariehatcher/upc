<?php
/**
 * @brief
 * Makes PEAR work with extentions installed in the home directory.
 * @file
 * Most shared hosts do not allow user installation of system-wide PEAR
 * extentions, so this file allows it to work with extentions installed
 * in the user's home directory. To make this work, you need to set the
 * HOME_PEAR_DIR constant to the path where your PEAR extentions are installed.
 * See that documentation for more info.
 */
/**
 * The location of PEAR extentions in the home directory.
 * This is usually @b /home/\<username\>/pear/php
 */
define('HOME_PEAR_DIR', '/home/dkeenan/pear/php');
set_include_path(get_include_path() . PATH_SEPARATOR . HOME_PEAR_DIR);