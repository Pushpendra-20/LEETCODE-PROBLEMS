/*
====================================================
LeetCode Problem: Second Highest Salary
Problem Number: 176

Approach:
- Select distinct salary values from
  the Employee table.

- Sort the salaries in descending
  order so the highest salary appears
  first.

- Use:
      LIMIT 1 OFFSET 1
  to retrieve the second highest
  distinct salary.

- Wrap the query inside another
  SELECT statement and rename the
  result as SecondHighestSalary.

- If a second highest salary does
  not exist, the query returns NULL,
  as required.

Query:

SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;

Why this approach?
- DISTINCT removes duplicate salary
  values.
- ORDER BY DESC ranks salaries from
  highest to lowest.
- OFFSET 1 skips the highest salary.
- LIMIT 1 returns the next distinct
  salary, which is the second highest.

Example:

Employee Table

+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+

Output

+----------------------+
| SecondHighestSalary  |
+----------------------+
| 200                  |
+----------------------+

Time Complexity: O(n log n)
Space Complexity: O(1)

Where:
n = number of rows in the Employee
table

Key Concepts:
- SQL
- DISTINCT
- ORDER BY
- LIMIT
- OFFSET
- Scalar Subquery

====================================================
*/




SELECT (
SELECT DISTINCT salary
FROM Employee
ORDER BY salary DESC
LIMIT 1 OFFSET 1
) AS SecondHighestSalary;
