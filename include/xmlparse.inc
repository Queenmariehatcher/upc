<?php
/**
 * @brief
 * Functions to parse XML data
 * @file
 * Functions to parse XML data.  Specifaclly created for use with isbndb.com
 */
require_once 'utils.inc';

/**
 * Parse XML Data from the given URL
 * @param $url Location of XML data
 * @return Object containing parsed XML data
 */
function parseXML($url) {
  /**
   * String containing raw, unparsed XML data
   */
  $xmlstr = fget($url);
  /**
   * Object containing parsed XML data
   */
  $xml = new SimpleXMLElement($xmlstr);

  return $xml;
}