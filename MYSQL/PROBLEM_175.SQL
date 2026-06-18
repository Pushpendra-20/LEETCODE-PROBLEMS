# /*

LeetCode Problem: Combine Two Tables
Problem Number: 175

Approach:

* Use a LEFT JOIN to combine the
  Person and Address tables.

* Join both tables using:
  personId

* LEFT JOIN ensures:

  * All records from the Person table
    are included.
  * Matching city and state values
    are fetched from the Address table.
  * If a person has no address,
    NULL values are returned for
    city and state.

Query:
SELECT p.firstName,
p.lastName,
a.city,
a.state
FROM Person p
LEFT JOIN Address a
ON p.personId = a.personId;

Why this approach?

* The problem requires displaying all
  persons regardless of whether an
  address exists.
* LEFT JOIN is specifically designed
  for this requirement.

Time Complexity: O(n + m)
Space Complexity: O(1)

Where:
n = rows in Person table
m = rows in Address table

Key Concepts:

* SQL
* LEFT JOIN
* Relational Databases
* Table Relationships

====================================================
*/



SELECT p.firstName,
       p.lastName,
       a.city,
       a.state
FROM Person p
LEFT JOIN Address a
ON p.personId = a.personId;
