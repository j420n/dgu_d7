<?php
/**
 * @file
 * dgu_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgu_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create dgu_news_article content'.
  $permissions['create dgu_news_article content'] = array(
    'name' => 'create dgu_news_article content',
    'roles' => array(
      'news editor' => 'news editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any dgu_news_article content'.
  $permissions['delete any dgu_news_article content'] = array(
    'name' => 'delete any dgu_news_article content',
    'roles' => array(
      'news editor' => 'news editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own dgu_news_article content'.
  $permissions['delete own dgu_news_article content'] = array(
    'name' => 'delete own dgu_news_article content',
    'roles' => array(
      'news editor' => 'news editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any dgu_news_article content'.
  $permissions['edit any dgu_news_article content'] = array(
    'name' => 'edit any dgu_news_article content',
    'roles' => array(
      'news editor' => 'news editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own dgu_news_article content'.
  $permissions['edit own dgu_news_article content'] = array(
    'name' => 'edit own dgu_news_article content',
    'roles' => array(
      'news editor' => 'news editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
