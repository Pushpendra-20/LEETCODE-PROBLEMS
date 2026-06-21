# /*

LeetCode Problem: Customers Who Never Order
Problem Number: 183

Approach:

* Use a LEFT JOIN to combine the
  Customers and Orders tables.

* Match records using:
  Customers.id = Orders.customerId

* LEFT JOIN ensures that all customers
  are included, even if they have not
  placed any orders.

* Customers without orders will have
  NULL values in the Orders columns.

* Filter those customers using:
  WHERE Orders.id IS NULL

Query:
SELECT Customers.name AS Customers
FROM Customers
LEFT JOIN Orders
ON Customers.id = Orders.customerId
WHERE Orders.id IS NULL;

Why this approach?

* The problem requires finding customers
  who have never placed an order.
* LEFT JOIN keeps all customers, and
  NULL values help identify those with
  no matching orders.

Example:

Customers Table

+----+-------+
| id | name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+

Orders Table

+----+------------+
| id | customerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+

Output

+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+

Time Complexity: O(n + m)
Space Complexity: O(1)

Where:
n = number of customers
m = number of orders

Key Concepts:

* SQL
* LEFT JOIN
* NULL Filtering
* Relational Databases

====================================================
*/



SELECT Customers.name AS Customers
FROM Customers
LEFT JOIN Orders
ON Customers.id = Orders.customerId
WHERE Orders.id IS NULL;
