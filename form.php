<?php
/**
 * @file
 * Functions for outputting the Barcode entry form
 */
/**
 * Creates an entry form for UPCs (and eventually other types of Barcodes
 *
 * @return The Barcode entry form
 */
function getEntryForm() {
  $form = <<<_HTML
              <form action="index.php" method="get">
                <fieldset>
                  <label>UPC:</label> <input type="text" name="upc" /><br />
                  <input type="submit" value="Submit" />
                </fieldset>
              </form>
_HTML;

  return $form;
}