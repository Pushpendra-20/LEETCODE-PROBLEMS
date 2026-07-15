/*
====================================================
LeetCode Problem: Climbing Stairs
Problem Number: 70

Approach:
- Use Dynamic Programming with
  Recursion (Memoization).

- Create a DP array initialized
  with -1 to store previously
  computed results.

- Define a recursive function
  solve(n):

    - If n == 1:
        Return 1 since there is
        only one way to reach
        the first stair.

    - If n == 2:
        Return 2 since there are
        two possible ways.

    - If the answer for n has
      already been computed,
      return it from the DP array.

    - Otherwise:
        Compute the result as:
        solve(n-1) + solve(n-2)

    - Store the result in the
      DP array before returning.

- In climbStairs():
    - Initialize the DP array.
    - Call solve(n).

Why this approach?
- The number of ways to reach the
  nth stair depends only on the
  previous two stairs.

- Memoization prevents repeated
  computation of the same
  subproblems, making recursion
  efficient.

- This follows the Fibonacci
  recurrence:
      ways(n) = ways(n-1) + ways(n-2)

Example:

Input:
n = 3

Recursion:
ways(3)
= ways(2) + ways(1)
= 2 + 1
= 3

Output:
3

Input:
n = 5

ways(5)
= ways(4) + ways(3)
= 5 + 3
= 8

Output:
8

Time Complexity: O(n)

Space Complexity: O(n)

Where:
n = number of stairs

Key Concepts:
- Dynamic Programming
- Memoization
- Recursion
- Fibonacci Sequence

Note:
This memoized solution computes
each state only once, giving O(n)
time complexity.

A further optimization uses an
iterative DP approach with only
two variables, reducing the space
complexity to O(1).

====================================================
*/



class Solution {
public:
    vector<int> dp;

    int solve(int n){
        if(n == 1) return 1;
        if(n == 2) return 2;

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = solve(n - 1) + solve(n - 2);
        return dp[n];
    }

    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};
