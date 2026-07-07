/*
====================================================
LeetCode Problem: Fibonacci Number
Problem Number: 509

Approach:
- Handle the base cases:
    - If n == 0, return 0.
    - If n == 1, return 1.

- For all other values:
    - Recursively compute the
      (n-1)th Fibonacci number.
    - Recursively compute the
      (n-2)th Fibonacci number.

- Return the sum of both recursive
  calls.

Why this approach?
- The Fibonacci sequence is
  naturally defined recursively:
      F(0) = 0
      F(1) = 1
      F(n) = F(n-1) + F(n-2)

- The recursive implementation
  directly follows this mathematical
  definition, making it simple and
  easy to understand.

Example:

Input:
n = 4

Recursion:
F(4)
= F(3) + F(2)
= (F(2)+F(1)) + (F(1)+F(0))
= (1+1) + (1+0)
= 3

Output:
3

Input:
n = 2

Output:
1

Input:
n = 5

Output:
5

Time Complexity: O(2^n)

Space Complexity: O(n)

Where:
n = input number

Key Concepts:
- Recursion
- Dynamic Programming
- Fibonacci Sequence

Note:
This recursive solution is easy to
understand but recomputes the same
subproblems multiple times, making
it inefficient for large values of
n. The optimal approaches are:
- Memoization (Top-Down DP): O(n)
- Tabulation (Bottom-Up DP): O(n)
- Space Optimized DP: O(n) time,
  O(1) space.

====================================================
*/






class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-2)+fib(n-1);
    }
};
