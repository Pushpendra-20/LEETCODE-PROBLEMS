# /*

LeetCode Problem: Primary Department for Each Employee
Problem Number: 1789

Approach:

* An employee can belong to one or
  more departments.

* There are two cases:

  1. Employee has a primary department
     (primary_flag = 'Y')

     * Select that department directly.

  2. Employee belongs to only one
     department.

     * Even if primary_flag is 'N',
       that department is considered
       the primary department.

* First query:

  * Retrieve all employees whose
    primary_flag is 'Y'.

* Second query:

  * Find employees appearing only
    once in the table using
    GROUP BY and HAVING COUNT(*) = 1.
  * Return their department.

* Use UNION to combine both results.

Query:

SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'

UNION

SELECT employee_id, department_id
FROM Employee
WHERE employee_id IN (
SELECT employee_id
FROM Employee
GROUP BY employee_id
HAVING COUNT(*) = 1
);

Why this approach?

* Employees with a designated primary
  department are selected directly.
* Employees belonging to only one
  department automatically have that
  department as their primary one.
* UNION merges both valid cases into
  the required result.

Example:

Employee Table

+-------------+---------------+--------------+
| employee_id | department_id | primary_flag |
+-------------+---------------+--------------+
| 1           | 1             | N            |
| 2           | 1             | Y            |
| 2           | 2             | N            |
| 3           | 3             | N            |
+-------------+---------------+--------------+

Output

+-------------+---------------+
| employee_id | department_id |
+-------------+---------------+
| 2           | 1             |
| 1           | 1             |
| 3           | 3             |
+-------------+---------------+

Time Complexity: O(n)
Space Complexity: O(n)

Where:
n = number of rows in Employee table

Key Concepts:

* SQL
* UNION
* GROUP BY
* HAVING
* Subqueries

====================================================
*/



SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'

UNION

SELECT employee_id, department_id
FROM Employee
WHERE employee_id IN (
    SELECT employee_id
    FROM Employee
    GROUP BY employee_id
    HAVING COUNT(*) = 1
);
