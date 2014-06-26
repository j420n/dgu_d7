@javascript
Feature: View the site glossary
In order for me to easily view and add content in the open data glossary
As a site user
I should be able to search the open data glossary and add new content from a glossary landing page

@api
Scenario: View glossary landing page as an anonymous user.
  Given I am on the homepage
  When I click "Interact"
  And I follow "Open data glossary"
  Then I should be on "/glossary"
  And "Open data glossary" item in "Interact" subnav should be active
  And I should see the following <breadcrumbs>
    | Glossary of Public Sector Information and Open Data Terminology |
  And I should see "Approved terms"
  And I should see "New terms"
  And I should see "All terms"
  And I should see the link "Log in to Suggest a new Term"
  And I should see "Click one of the letters above to advance the page to terms beginning with that letter."
  And I should see "This glossary is intended to be an authoritative explanation of the meaning of technical terms, for all users of data.gov.uk."
  And I should see "AGGREGATED DATA"
  And I should see "VALUE-ADDED INFORMATION"

@api
Scenario: Endorse a term as an authenticated user
  Given that the user "test_user" is not registered
  When I am logged in as a user "test_user" with the "authenticated user" role
  And I am on "/glossary"
  Then I should see the lexicon links
  When I click "D"
  And I follow "Disclosive"
  Then I should see "Data is potentially disclosive"
  When I click "Endorse"
  Then I should see "Your vote has been recorded"
  And I should see "Cancel Endorsement"

@api
Scenario: Suggest a new term as an authenticated user and get it moderated
  Given that the user "test_user" is not registered
  When I am logged in as a user "test_user" with the "authenticated user" role
  And I am on "/glossary"
  When I follow "Suggest a new Term"
  Then I should be on "/glossary/suggest_new"
  And I should see "You are creating new content, this may be placed in moderation and may not be immediately visible on the site."
  And I should see the following <breadcrumbs>
    | Glossary of Public Sector Information and Open Data Terminology |
    | Suggest new term and definition                                 |
  When I fill in "Term name" with "Name of new term suggestion"
  And I fill in "suggested definition" with "Brief suggested term definition"
  And I fill in "Reason for change" with "A reason for the new suggestion"
  And I press "Save draft"
  Then I should see the following <breadcrumbs>
    | Glossary of Public Sector Information and Open Data Terminology |
    | Thank you for your suggestion                                   |
  And I should see "Your draft Suggested term has been created. You can update it in My Drafts section."
  And I should see "Thank you for your suggestion. We will normally respond to your suggestion within 5 working days"
  And I should see the link "Glossary"
  And I should see the link "My Drafts"
  And I should be on "/glossary/thanks"
  When I submit "Suggested term" titled "Name of new term suggestion" for moderation
  And user with "moderator" role moderates "Name of new term suggestion" authored by "test_user"
  And I follow "View published"
  Then I should be on "/name-new-term-suggestion"
  And I should see node title "Name of new term suggestion"
  And Node header should match "Submitted by \w* on \w*, \d*\/\d*\/\d* - \d*:\d*"
  And Node header should match "Updated on \w*, \d*\/\d*\/\d* - \d*:\d*"
  And Node field "suggested-definition" should match "^suggested definition:  Brief suggested term definition$"
  And Node field "reason-for-change" should match "^Reason for change:  A reason for the new suggestion$"

@api
Scenario: Add a term as an administrator and check if it is displayed in the New terms page then add a new commment as an authenticated user.
  Given I am not logged in
  And that the user "test_admin" is not registered
  When I am logged in as a user "test_admin" with the "administrator" role
  And I am on "/glossary"
  When I follow "Add term"
  Then I should be on "/admin/structure/taxonomy/glossary/add/term"
  When I fill in "Name" with "Name of new term suggestion"
  And I type "Brief suggested term definition" in the "edit-description-value" WYSIWYG editor
  And I check the box "is_new"
  And I press "Save"
  Then I should see "Created new term Name of new term suggestion."
  Given I am on "/glossary"
  And I follow "New terms"
  Then I should see "Name of new term suggestion"
  And I should see "Brief suggested term definition"
  # Testing comments as test commenting user
  Given that the user "test_commenting_user" is not registered
  And I am logged in as a user "test_commenting_user" with the "authenticated user" role
  And I am on "/glossary"
  When I follow "New terms"
  And I follow "Name of new term suggestion"
  And I follow "Add new comment"
  Then I should see the following <breadcrumbs>
    | Glossary of Public Sector Information and Open Data Terminology |
    | Name of new term suggestion                                     |
    | Comment                                                         |
  When I fill in "Subject" with "Test subject"
  And I type "Test comment" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
  And I press "Submit"
  And I wait until the page loads
  Then I should see the success message "Comment was successfully created."
  And I should see the heading "Comments"
  And I should see "Test subject"
  And I should see "Test comment"
  And I should see the link "Edit"
  And I should see the link "Reply"
  And I should see "Posted by test_commenting_user"

  @api
  Scenario: Search for a term as an administrator using the lexicon extra link
    Given that the user "test_admin" is not registered
    When I am logged in as a user "test_admin" with the "administrator" role
    And I am on "/glossary"
    Then Term title "AGGREGATED DATA" should contain "SEARCH FOR TERM" extra link in glossary term