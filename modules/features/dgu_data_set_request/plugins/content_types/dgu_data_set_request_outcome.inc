<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Data requests by outcome'),
  'description' => t('Visualisation of data request by outcome field.'),
  'category' => 'Miscellaneous',
  'render callback' => 'dgu_data_set_request_outcome_render',
  'defaults' => array(
    'title_override' => FALSE,
    'title_override_text' => '',
  ),
);

/**
 * Renders report about data requests outcome.
 */
function dgu_data_set_request_outcome_render($subtype, $conf, $panel_args, $context) {

  $query = db_select('field_data_field_review_outcome', 'o');
  $query->join('field_data_field_review_status', 's', 's.entity_id = o.entity_id');
  $query->join('node', 'n', 's.entity_id = n.nid');
  $query->fields('o', array('field_review_outcome_value'))
    ->groupBy('field_review_outcome_value')
    ->condition('n.status', 1)
    ->condition('field_review_status_value', 6)
    ->addExpression('COUNT(o.entity_id)', 'outcome_count');
  $result = $query->execute();

  $outcome_field_info = field_info_field('field_review_outcome');
  $allowed_values = list_allowed_values($outcome_field_info);

  $rows = array();
  foreach($result as $row) {
    $rows[] = array($allowed_values[$row->field_review_outcome_value], $row->outcome_count);
  }

  $chart = array(
    'id' => 'data_requests_by_outcome',
    'type' => 'piechart',
    'rows' => $rows,
  );

  $block = new stdClass();
  $block->content = d3_draw($chart);

  return $block;
}

/**
 * Empty form so we can have the default override title.
 */
function dgu_data_set_request_outcome_render_edit_form($form, &$form_state) {
  return $form;
}

