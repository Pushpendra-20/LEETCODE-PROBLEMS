# /*

LeetCode Problem: Employees Earning More Than Their Managers
Problem Number: 181

Approach:

* Perform a self JOIN on the Employee table.

* Treat:
  e1 = Employee
  e2 = Manager

* Match employees with their managers
  using:
  e1.managerId = e2.id

* Compare salaries:

  * If employee salary is greater
    than manager salary,
    include the employee's name
    in the result.

Query:
SELECT e1.name AS Employee
FROM Employee e1
JOIN Employee e2
ON e1.managerId = e2.id
WHERE e1.salary > e2.salary;

Why this approach?

* Managers and employees are stored
  in the same table.
* A self JOIN allows us to compare
  rows within the same table.

Example:

Employee Table

+----+-------+--------+-----------+
| id | name  | salary | managerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+

Output:

+----------+
| Employee |
+----------+
| Joe      |
+----------+

Time Complexity: O(n)
Space Complexity: O(1)

Key Concepts:

* SQL
* Self JOIN
* Filtering
* Relational Databases

====================================================
*/



SELECT e1.name AS Employee
FROM Employee e1
JOIN Employee e2
    ON e1.managerId = e2.id
WHERE e1.salary > e2.salary;
