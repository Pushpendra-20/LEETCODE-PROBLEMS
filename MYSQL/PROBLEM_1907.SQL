# /*

LeetCode Problem: Count Salary Categories
Problem Number: 1907

Approach:

* Divide all accounts into three salary
  categories based on income:

  1. Low Salary
     income < 20000

  2. Average Salary
     income BETWEEN 20000 AND 50000

  3. High Salary
     income > 50000

* For each category:

  * Count the number of accounts
    that belong to it.

* Use UNION to combine the results
  into a single output table.

Query:

SELECT 'Low Salary' AS category,
COUNT(*) AS accounts_count
FROM Accounts
WHERE income < 20000

UNION

SELECT 'Average Salary' AS category,
COUNT(*) AS accounts_count
FROM Accounts
WHERE income BETWEEN 20000 AND 50000

UNION

SELECT 'High Salary' AS category,
COUNT(*) AS accounts_count
FROM Accounts
WHERE income > 50000;

Why this approach?

* Each SELECT calculates the count
  for one salary category.
* UNION combines all categories into
  a single result set.
* COUNT(*) ensures that even when
  no accounts match a category,
  the category still appears with
  a count of 0.

Example:

Accounts Table

+----+--------+
| id | income |
+----+--------+
| 1  | 12000  |
| 2  | 45000  |
| 3  | 70000  |
+----+--------+

Output

+----------------+---------------+
| category       | accounts_count|
+----------------+---------------+
| Low Salary     | 1             |
| Average Salary | 1             |
| High Salary    | 1             |
+----------------+---------------+

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of rows in Accounts table

Key Concepts:

* SQL
* UNION
* COUNT
* Conditional Filtering
* Aggregation

====================================================
*/



SELECT 'Low Salary' AS category,
       COUNT(*) AS accounts_count
FROM Accounts
WHERE income < 20000

UNION

SELECT 'Average Salary' AS category,
       COUNT(*) AS accounts_count
FROM Accounts
WHERE income BETWEEN 20000 AND 50000

UNION

SELECT 'High Salary' AS category,
       COUNT(*) AS accounts_count
FROM Accounts
WHERE income > 50000;
