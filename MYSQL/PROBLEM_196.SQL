# /*

LeetCode Problem: Delete Duplicate Emails
Problem Number: 196

Approach:

* Perform a self JOIN on the Person table.

* Compare records having the same
  email address.

* Keep the record with the smallest
  Id value.

* Delete records where:
  p1.Email = p2.Email
  and
  p1.Id > p2.Id

* This ensures that for every duplicate
  email, only the row with the lowest
  Id remains.

Query:
DELETE p1
FROM Person p1, Person p2
WHERE p1.Email = p2.Email
AND p1.Id > p2.Id;

Why this approach?

* The problem requires removing
  duplicate emails while retaining
  exactly one copy.
* The smallest Id is preserved as the
  original record.
* All other duplicate entries are
  deleted.

Example:

Person Table

+----+---------+
| Id | Email   |
+----+---------+
| 1  | [a@b.com](mailto:a@b.com) |
| 2  | [c@d.com](mailto:c@d.com) |
| 3  | [a@b.com](mailto:a@b.com) |
+----+---------+

After Deletion

+----+---------+
| Id | Email   |
+----+---------+
| 1  | [a@b.com](mailto:a@b.com) |
| 2  | [c@d.com](mailto:c@d.com) |
+----+---------+

Time Complexity: O(n²)
Space Complexity: O(1)

Key Concepts:

* SQL
* DELETE Statement
* Self JOIN
* Duplicate Removal
* Data Cleaning

====================================================
*/




DELETE p1
FROM Person p1, Person p2
WHERE p1.Email = p2.Email
AND p1.Id > p2.Id;
