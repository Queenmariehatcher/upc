<?php
/**
 * @brief
 * Functions for outputting the Barcode entry form
 * @file
 * This file currently contains functions that relate to various forms.
 * As there is currently only one form, this file may seem redundant.
 * However, it stays for the sake of forward compatability.
 */
/**
 * Creates an entry form for UPCs (and eventually other types of Barcodes
 * @return The Barcode entry form
 */
function getEntryForm() {
  /**
   * String containing the Barcode entry form
   */
  $form = <<<_HTML
              <form action="index.php" method="get" id="codeentry">
                <fieldset>
                  <label>UPC:</label><input type="text" name="upc" /><br />
                  <label class="radiolabel">UPC</label><input type="radio" checked="true" name="type" value="upc" />
                  <label class="radiolabel">ISBN</label><input type="radio" name="type" value="isbn" /><br />
                  <input type="submit" value="Submit" />
                </fieldset>
              </form>
_HTML;

  return $form;
}