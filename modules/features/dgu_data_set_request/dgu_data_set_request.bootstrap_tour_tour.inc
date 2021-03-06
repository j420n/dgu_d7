<?php
/**
 * @file
 * dgu_data_set_request.bootstrap_tour_tour.inc
 */

/**
 * Implements hook_default_bootstrap_tour().
 */
function dgu_data_set_request_default_bootstrap_tour() {
  $export = array();

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'data_request_administration';
  $bootstrap_tour->title = 'Data request administration';
  $bootstrap_tour->roles = '3,10';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'Data request adminisration tour';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '.nav-user',
      'path' => 'help',
      'placement' => 'left',
      'title' => 'User account',
      'content' => '<p>To access the data requests administration functions please go to the user account page.</p>

<p>At this stage all new data requests should be already moderated.</p>

<p><a href="/user?tour=content_moderation">Play content moderation tour</a></p>
',
      'format' => 'filtered_html',
    ),
    1 => array(
      'selector' => 'a[href="/admin/workbench"]',
      'path' => 'user',
      'placement' => 'bottom',
      'title' => 'Manage my content',
      'content' => '<p>Next please click &#39;Manage my content&#39; tab.</p>
',
      'format' => 'filtered_html',
    ),
    2 => array(
      'selector' => 'a[href="/admin/workbench/content/data-requests"]',
      'path' => 'admin/workbench',
      'placement' => 'bottom',
      'title' => 'List of all data requests',
      'content' => '<p>Then click &#39;Data Requests&#39;&nbsp;tab to access the data requests administration page.</p>
',
      'format' => 'filtered_html',
    ),
    3 => array(
      'selector' => '.view-data-requests-administration .views-table',
      'path' => 'admin/workbench/content/data-requests',
      'placement' => 'top',
      'title' => 'List of all data request',
      'content' => '<p>This contains a list of all active and closed&nbsp;data requests for all publishers and Relationship Managers, you can narow down nubmer of requests displayed using filters above.</p>
',
      'format' => 'filtered_html',
    ),
    4 => array(
      'selector' => '#edit-title',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Title filter',
      'content' => '<p>You can search through the titles, entering any string contained in the title to perform the search.<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    5 => array(
      'selector' => '#edit-field-review-status-value',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Status filter',
      'content' => '<p>You can also flter requests by their status.&nbsp; In order to do that please select the status filter from the drop down list.</p>
',
      'format' => 'filtered_html',
    ),
    6 => array(
      'selector' => '#edit-field-publication-preference-value',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Publication preference filter',
      'content' => '<p>You can also filter by publication preference...<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    7 => array(
      'selector' => '#edit-field-review-outcome-value',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Outcome filter',
      'content' => '<p>... or by request&nbsp;outcome. Setting the outcome filter narrows down the results to only&nbsp;data requests with the status &#39;Closed&#39;, because the&nbsp;&#39;Outcome&#39; field is available only for closed requests.</p>
',
      'format' => 'filtered_html',
    ),
    8 => array(
      'selector' => '#edit-field-barriers-reason-value',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Issue filter',
      'content' => '<p>You can use &#39;issue&#39; filter in similar way to&nbsp;status and outcome filters.<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    9 => array(
      'selector' => '#edit-items-per-page',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Items per page',
      'content' => '<p>Here you can choose the number of&nbsp;data requests that will be displayed&nbsp;on the list per page.</p>
',
      'format' => 'filtered_html',
    ),
    10 => array(
      'selector' => '#edit-submit-data-requests-administration',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Apply button',
      'content' => '<p>Please don&#39;t forget to press &#39;Apply&#39; button to apply filters.<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    11 => array(
      'selector' => 'th.views-field-changed',
      'path' => '',
      'placement' => 'top',
      'title' => 'Default sort',
      'content' => '<p>By default the list is sorted&nbsp;by modification date.&nbsp;You can change this by clicking on other column labels.</p>
',
      'format' => 'filtered_html',
    ),
    12 => array(
      'selector' => '.views-row-first .views-field-title a',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Link to the data request',
      'content' => '<p>The title of the data request is the link to the data request view page.</p>
',
      'format' => 'filtered_html',
    ),
    13 => array(
      'selector' => '.views-row-first .views-field-edit-node a',
      'path' => '',
      'placement' => 'left',
      'title' => 'Edit link',
      'content' => '<p>This is the link to the data request edit page.</p>
',
      'format' => 'filtered_html',
    ),
    14 => array(
      'selector' => '.views-row-first .views-field-field-assignee a',
      'path' => '',
      'placement' => 'left',
      'title' => 'Link to user profile',
      'content' => '<p>Data request assignee is the link to data.gov.uk user profile.<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    15 => array(
      'selector' => '.text-center .pagination',
      'path' => '',
      'placement' => 'top',
      'title' => 'Pager',
      'content' => '<p>You can&nbsp;navigate through all the data request pages here.</p>
',
      'format' => 'filtered_html',
    ),
    16 => array(
      'selector' => 'a[href="/admin/workbench/content/active"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Active Data requests',
      'content' => '<p>To manage data requests currently assigned to you please click &#39;Active Data requests&#39; tab.</p>
',
      'format' => 'filtered_html',
    ),
    17 => array(
      'selector' => '.view-data-requests-administration .view-content',
      'path' => 'admin/workbench/content/active',
      'placement' => 'top',
      'title' => 'Active Data requests',
      'content' => '<p>This is very similar list to &#39;Data requests&#39; just without &#39;Assignee&#39; column because they are all assigned to you.</p>
',
      'format' => 'filtered_html',
    ),
    18 => array(
      'selector' => '.view-data-requests-administration .view-filters form',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Fitlers',
      'content' => '<p>The filters&nbsp;work&nbsp;in the same way as&nbsp;on the data requests list.</p>
',
      'format' => 'filtered_html',
    ),
    19 => array(
      'selector' => 'a[href="/admin/workbench/content/edited"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'My Edits',
      'content' => '<p>You can find all requests you have edited (e.g. assigned to somebody else) here.</p>
',
      'format' => 'filtered_html',
    ),
    20 => array(
      'selector' => '.views-row-first .views-field-edit-node a',
      'path' => 'admin/workbench/content/data-requests',
      'placement' => 'left',
      'title' => 'Edit link',
      'content' => '<p>To edit a data request please click edit link.</p>
',
      'format' => 'filtered_html',
    ),
    21 => array(
      'selector' => '.tabs--primary a[href="/node/651/edit"]',
      'path' => 'node/651/edit',
      'placement' => 'bottom',
      'title' => 'Editing data request',
      'content' => '<p>You are now on the data request edit page.</p>
',
      'format' => 'filtered_html',
    ),
    22 => array(
      'selector' => '.tabs--primary a[href="/data-request/test-data"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Virew data request',
      'content' => '<p>Click &#39;View&#39; to switch to data request view page.</p>
',
      'format' => 'filtered_html',
    ),
    23 => array(
      'selector' => '.tabs--primary a[href="/node/651/moderation"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Moderation',
      'content' => '<p>Click &#39;Moderate&#39; to see the moderation history, unpublish or change the moderation state of the current revision.</p>
',
      'format' => 'filtered_html',
    ),
  );
  $export['data_request_administration'] = $bootstrap_tour;

  return $export;
}
