<?php
/**
 * @file
 * Template for the Atom XML used to create deposits.
 * 
 * Available variables:
 *   $au_title string
 *     The AU's title.
 *   $site_name string
 *     The value of variable_get('site_name', '').
 *   $entries array
 *     An array of the content URLs.
 */
?>
<entry xmlns="http://www.w3.org/2005/Atom"
        xmlns:dcterms="http://purl.org/dc/terms/"
        xmlns:lom="http://lockssomatic.info/SWORD2">
  <title><?php print $au_title; ?></title>
  <id>urn:uuid:<?php print $uuid; ?></id>
  <updated>2013-10-07T17:17:08Z</updated>
  <summary type="text">Content deposited to LOCKSS-O-Matic by content provider <?php print $site_name; ?>.</summary>
  <?php foreach ($entries as $entry) : ?>
  <lom:content size="<?php print $entry['size']; ?>" checksumType="<?php print $entry['checksum_type']; ?>" checksumValue="<?php print $entry['checksum_value']; ?>"><?php print $entry['url']; ?></lom:content>
  <?php endforeach; ?>
</entry>
