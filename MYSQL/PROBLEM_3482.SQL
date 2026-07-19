/*
====================================================
LeetCode Problem: Analyze Organization Hierarchy
Problem Number: 3482

Approach:

The solution uses Recursive Common
Table Expressions (CTEs) to build
the employee hierarchy and compute
each employee's team size and
budget.

----------------------------------------------------
Step 1: Build Employee Hierarchy
----------------------------------------------------

EmployeeHierarchy CTE

- Start with the top-level employee
  (manager_id IS NULL).

- Assign:
    level = 1

- Recursively join employees whose
  manager_id matches the current
  employee_id.

- Increase the hierarchy level by
  one for every recursive step.

This generates:

employee_id
employee_name
manager_id
salary
level

----------------------------------------------------
Step 2: Find All Subordinates
----------------------------------------------------

Subordinates CTE

- Begin with every direct
  manager-employee relationship.

- Recursively expand to include
  indirect subordinates.

- Continue until every employee
  under each manager is found.

----------------------------------------------------
Step 3: Calculate Team Size
and Budget
----------------------------------------------------

For every employee:

- Count all distinct employees
  reporting under them.

COUNT(DISTINCT employee_id)

- Sum the salaries of every
  subordinate.

- Add the employee's own salary.

budget =
employee salary +
sum(all subordinate salaries)

----------------------------------------------------
Step 4: Generate Final Result
----------------------------------------------------

Join:

EmployeeHierarchy
        +
TeamSizeAndBudget

Return:

employee_id
employee_name
level
team_size
budget

Sort by:

1. level (ascending)
2. budget (descending)
3. employee_name (ascending)

----------------------------------------------------
Why this approach?

- Recursive CTE efficiently models
  hierarchical organizational
  structures.

- Every employee is assigned the
  correct hierarchy level.

- Another recursive traversal
  collects every direct and
  indirect subordinate.

- Aggregation computes each
  employee's complete team size
  and department budget.

- LEFT JOIN ensures employees
  without subordinates are still
  included.

----------------------------------------------------
Example

Employees

CEO (100)

├── Alice (80)

│   ├── Bob (50)

│   └── Carol (40)

└── David (60)

Output

CEO

Level = 1
Team Size = 4
Budget = 330

Alice

Level = 2
Team Size = 2
Budget = 170

David

Level = 2
Team Size = 0
Budget = 60

Bob

Level = 3
Team Size = 0
Budget = 50

Carol

Level = 3
Team Size = 0
Budget = 40

----------------------------------------------------
Time Complexity

Hierarchy Construction:
O(n)

Subordinate Expansion:
O(n²) worst case

Aggregation:
O(n)

Overall:
O(n²)

----------------------------------------------------
Space Complexity

O(n)

for recursive CTEs and
intermediate results.

----------------------------------------------------
Key Concepts

- SQL
- Recursive CTE
- Hierarchical Queries
- Self Join
- GROUP BY
- COUNT
- SUM
- LEFT JOIN
- Aggregation

----------------------------------------------------
Note

Recursive CTEs are the standard
SQL approach for solving
hierarchical organization
problems. This solution computes
employee levels, total team size,
and department budgets in a clear
and efficient manner.

====================================================
*/


PROBLEM 3482

WITH RECURSIVE 
EmployeeHierarchy AS (
    SELECT
        employee_id,
        employee_name,
        manager_id,
        salary,
        1 AS level
    FROM Employees
    WHERE manager_id IS NULL

    UNION ALL

    SELECT
        e.employee_id,
        e.employee_name,
        e.manager_id,
        e.salary,
        eh.level + 1
    FROM Employees e
    JOIN EmployeeHierarchy eh
        ON e.manager_id = eh.employee_id
),

TeamSizeAndBudget AS (
    WITH RECURSIVE
    Subordinates AS (
        SELECT
            manager_id,
            employee_id,
            salary
        FROM Employees
        WHERE manager_id IS NOT NULL

        UNION ALL

        SELECT
            s.manager_id,
            e.employee_id,
            e.salary
        FROM Employees e
        JOIN Subordinates s
            ON e.manager_id = s.employee_id
    )

    SELECT
        e.employee_id,
        COUNT(DISTINCT s.employee_id) AS team_size,
        IFNULL(SUM(s.salary), 0) + e.salary AS budget
    FROM Employees e
    LEFT JOIN Subordinates s
        ON e.employee_id = s.manager_id
    GROUP BY e.employee_id, e.salary
)

SELECT
    eh.employee_id,
    eh.employee_name,
    eh.level,
    IFNULL(tb.team_size, 0) AS team_size,
    IFNULL(tb.budget, eh.salary) AS budget
FROM EmployeeHierarchy eh
LEFT JOIN TeamSizeAndBudget tb
    USING(employee_id)
ORDER BY
    eh.level,
    budget DESC,
    eh.employee_name;
