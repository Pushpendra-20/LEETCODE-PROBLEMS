# /*

LeetCode Problem: Duplicate Emails
Problem Number: 182

Approach:

* Group all records by Email.

* Use COUNT(Email) to calculate
  how many times each email appears.

* Filter only those emails whose
  count is greater than 1 using
  the HAVING clause.

Query:
SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;

Why this approach?

* GROUP BY creates a group for each
  unique email address.
* COUNT(Email) determines the
  frequency of each email.
* HAVING filters grouped results
  based on aggregate values.

Example:

Person Table

+----+---------+
| Id | Email   |
+----+---------+
| 1  | [a@b.com](mailto:a@b.com) |
| 2  | [c@d.com](mailto:c@d.com) |
| 3  | [a@b.com](mailto:a@b.com) |
+----+---------+

Output

+---------+
| Email   |
+---------+
| [a@b.com](mailto:a@b.com) |
+---------+

Time Complexity: O(n)
Space Complexity: O(n)

Where:
n = number of rows in the Person table

Key Concepts:

* SQL
* GROUP BY
* HAVING
* Aggregate Functions

====================================================
*/




SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;
