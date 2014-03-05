<?php

/**
 * @file
 * The admin form for the islandora checksum module.
 */

/**
 * Defines the admin settings form.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_lockssomatic_admin_form(array $form, array &$form_state) {
  global $base_url;
  $form['islandora_lockssomatic_configuration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Islandora LOCKSS-O-Matic configuration'),
  );

  $form['islandora_lockssomatic_configuration']['islandora_lockssomatic_lom_base_url'] = array(
    '#type' => 'textfield',
    '#title' => t("LOCKSS-O-matic's base URL"),
    '#default_value' => variable_get('islandora_lockssomatic_lom_base_url', 'http://example.com/lockssomatic'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#description' => t('Do not include the trailing slash.'),
  );
  $form['islandora_lockssomatic_configuration']['islandora_lockssomatic_content_provider_id'] = array(
    '#type' => 'textfield',
    '#title' => t("Islandora's LOCKSS-O-Matic Content Provider ID"),
    '#default_value' => variable_get('islandora_lockssomatic_content_provider_id', '10'),
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => TRUE,
    '#description' => t("You can get this value in Islandora's Content Provider entry in LOCKSS-O-Matic."),
  );

  $harvest_dir = variable_get('file_public_path', conf_path() . '/files/lockssomatic');
  $form['islandora_lockssomatic_configuration']['islandora_lockssomatic_harvest_directory'] = array(
    '#title' => t('Harvest directory'),
    '#type' => 'textfield',
    '#size' => 60,
    '#default_value' => variable_get('islandora_lockssomatic_harvest_directory', $harvest_dir),
    '#description' => t("Filesystem path to the directory where your objects' Bags are harvested
      from, relative to the Drupal installation directory. Needs to exist and to be writable by
      the web server. Do not include the trailing slash."),
    '#maxlength' => 255,
    '#required' => TRUE,
  );

  $form['islandora_lockssomatic_configuration']['islandora_lockssomatic_move_copy'] = array(
    '#type' => 'select',
    '#title' => t('Move or copy Bag'),
    '#default_value' => variable_get('islandora_lockssomatic_move_copy', 1),
    '#options' => array(
      '1' => t('Move'),
      '0' => t('Copy'),
    ),
    '#description' => t('Move or copy the Bags into the harvest directory.'),
  );

  $lockss_permission_statement = $base_url . '/islandora/lockss/permission';
  $form['islandora_lockssomatic_configuration']['islandora_lockssomatic_lockss_permission_url'] = array(
    '#markup' => t("Islandora's LOCKSS Permission Statement URL is: !lps", array('!lps' => $lockss_permission_statement)),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );
  $lockss_base_url = $base_url . '/' . variable_get('islandora_lockssomatic_harvest_directory', $harvest_dir);
  $form['islandora_lockssomatic_configuration']['islandora_lockssomatic_lockss_base_url'] = array(
    '#markup' => t("Islandora's LOCKSS base URL is: !lbu", array('!lbu' => $lockss_base_url)),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );
  return system_settings_form($form);
}
