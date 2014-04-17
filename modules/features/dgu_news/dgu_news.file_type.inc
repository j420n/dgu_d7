<?php
/**
 * @file
 * dgu_news.file_type.inc
 */

/**
 * Implements hook_file_default_types().
 */
function dgu_news_file_default_types() {
  $export = array();

  $file_type = new stdClass();
  $file_type->disabled = FALSE; /* Edit this to true to make a default file_type disabled initially */
  $file_type->api_version = 1;
  $file_type->type = 'application';
  $file_type->label = 'Application';
  $file_type->description = 'Multipurpose type - kept to support older sites.';
  $file_type->mimetypes = '';
  $export['application'] = $file_type;

  return $export;
}
