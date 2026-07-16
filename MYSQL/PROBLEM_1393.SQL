/*
====================================================
LeetCode Problem: Capital Gain/Loss
Problem Number: 1393

Approach:
- Group all transactions by
  stock_name.

- Use a CASE expression to:
    - Add the price when the
      operation is 'Sell'.
    - Subtract the price when the
      operation is 'Buy'.

- Calculate the net capital
  gain/loss using SUM().

- Return:
    - stock_name
    - capital_gain_loss

Query:

SELECT
    stock_name,
    SUM(
        CASE
            WHEN operation = 'Sell' THEN price
            ELSE -price
        END
    ) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name;

Why this approach?
- Buying a stock represents an
  expense, so its price is
  subtracted.
- Selling a stock generates
  income, so its price is added.
- Summing all transactions for
  each stock directly computes the
  overall capital gain or loss.

Example:

Stocks

+------------+-----------+-------+
| stock_name | operation | price |
+------------+-----------+-------+
| AAPL       | Buy       | 1000  |
| AAPL       | Sell      | 1500  |
| TSLA       | Buy       | 500   |
| TSLA       | Sell      | 450   |
+------------+-----------+-------+

Calculation:

AAPL:
-1000 + 1500 = 500

TSLA:
-500 + 450 = -50

Output:

+------------+-------------------+
| stock_name | capital_gain_loss |
+------------+-------------------+
| AAPL       | 500               |
| TSLA       | -50               |
+------------+-------------------+

Time Complexity: O(n)

Space Complexity: O(k)

Where:
n = number of transactions
k = number of distinct stocks

Key Concepts:
- SQL
- CASE
- SUM
- GROUP BY
- Aggregate Functions

Note:
This is the optimal solution.
Using CASE inside SUM computes
the net gain/loss in a single
aggregation without requiring
multiple queries or joins.

====================================================
*/


SELECT
    stock_name,
    SUM(
        CASE
            WHEN operation = 'Sell' THEN price
            ELSE -price
        END
    ) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name;
