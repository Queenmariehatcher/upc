<?php
/**
 * @file
 * Returns info on a given UPC Barcode
 * @todo
 * Make this support everyhting Image_Barcode supports:
 * - Code 39
 * - Code 128
 * - EAN 13
 * - INT 25
 * - PostNet
 * - UPCA
 * @todo
 * Return Manufacturer and Product Info for given UPC
 */
include('pear.inc');
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <meta name="generator" content=
  "HTML Tidy for Linux/x86 (vers 1 September 2005), see www.w3.org" />
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
        if (!$_GET) {
          echo <<<_HTML
            <form action="index.php" method="get">
              <fieldset>
                <label>UPC:</label> <input type="text" name="upc" /><br />
                <input type="submit" value="Submit" />
              </fieldset>
            </form>
_HTML;
        }
        else {
          echo '<div id="upc">';
          echo '<img src="upcimg.php?upc=' . $_GET['upc'] . '" />';
          echo '</div>';
        }
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
