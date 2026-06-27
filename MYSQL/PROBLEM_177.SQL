# /*

LeetCode Problem: Nth Highest Salary
Problem Number: 177

Approach:

* The function accepts an integer N,
  representing the desired highest
  salary.

* Since SQL OFFSET starts from 0:
  N = N - 1

* Retrieve distinct salaries from the
  Employee table.

* Sort the salaries in descending
  order so the highest salary appears
  first.

* Use:
  LIMIT 1 OFFSET N
  to fetch the Nth highest distinct
  salary.

* If the requested salary does not
  exist, the function returns NULL.

Query:

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N - 1;

```
RETURN (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET N
);
```

END

Why this approach?

* DISTINCT removes duplicate salary
  values.
* ORDER BY DESC ranks salaries from
  highest to lowest.
* OFFSET skips the first N salaries,
  allowing the query to return the
  required Nth highest salary.

Example:

Employee Table

+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+

Input:
N = 2

Output:
200

Time Complexity: O(n log n)
Space Complexity: O(1)

Where:
n = number of rows in the Employee
table

Key Concepts:

* SQL
* User-Defined Functions
* DISTINCT
* ORDER BY
* LIMIT
* OFFSET

====================================================
*/



CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;

    RETURN (
        SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC
        LIMIT 1 OFFSET N
    );
END
