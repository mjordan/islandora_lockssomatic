<?php

/**
 * @file
 * Drush integration file for the Islandora LOCKSS-O-Matic module.
 *
 * Usage: drush create-islandora-lom-deposit "Title"
 *   where "Title" is the title that will be assigned to the
 *   deposit corresponding and LOCKSS Archival Unit.
 */

/**
 * Implements hook_drush_help().
 */
function islandora_lockssomatic_drush_help($command) {
  switch ($command) {
    case 'drush:create-islandora-lom-deposit':
      return dt('Create a deposit for LOCKSS-O-Matic');
  }
}

/**
 * Implements hook_drush_command().
 */
function islandora_lockssomatic_drush_command() {
  $items = array();
  $items['create-islandora-lom-deposit'] = array(
    'description' => dt('Create a deposit for LOCKSS-O-Matic.'),
    'arguments'   => array(
      '"Title"'  => dt('Optional. The title that will be assigned to the deposit corresponding and LOCKSS Archival Unit. If provided, must be surrounded in quotes.'),
    ),
    'examples' => array(
      'Standard example' => 'drush create-islandora-lom-deposit "New Islandora objects 2014-06"',
      'Alias example' => 'drush lomdep "New Islandora objects 2014-06"',
    ),
    'aliases' => array('lomdep'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  return $items;
}

/**
 * Callback function for drush create-islandora-bag. 
 *
 * @param string $name
 *   The name that will be assigned to the deposit corresponding and
 *   LOCKSS Archival Unit. Must be surrounded in quotes.
 */
function drush_islandora_lockssomatic_create_islandora_lom_deposit($name = NULL) {
  if (variable_get('islandora_lockssomatic_use_cron', 1)) {
    drush_print('This command only works if you have unchecked "Create \'In progress\' deposits via cron" in Islandora LOCKSS-O-Matic\'s admin settings.');
  }
  else {
    drush_print('Creating SWORD Deposit');
    islandora_lockssomatic_create_deposit(FALSE, $name);
  }
}
