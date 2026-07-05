/*
====================================================
LeetCode Problem: Perfect Number
Problem Number: 507

Approach:
- Handle the edge case:
    - If num <= 1, return false
      since 1 is not a perfect
      number.

- Initialize a variable `sum` to 0.

- Traverse all integers from
  1 to num / 2.

- For each integer:
    - Check if it divides num
      without leaving a remainder.
    - If it is a divisor, add it
      to the sum.

- After the loop:
    - Compare sum with num.
    - If they are equal, return true.
    - Otherwise, return false.

Why this approach?
- A perfect number is equal to the
  sum of all its positive divisors,
  excluding itself.
- Every proper divisor of a number
  is less than or equal to num / 2,
  so checking beyond that is
  unnecessary.

Example:

Input:
num = 28

Divisors:
1, 2, 4, 7, 14

Sum:
1 + 2 + 4 + 7 + 14 = 28

Output:
true

Input:
num = 7

Divisors:
1

Sum:
1

Output:
false

Time Complexity: O(n)

Space Complexity: O(1)

Where:
n = value of the input number

Key Concepts:
- Math
- Divisors
- Iteration

Note:
The optimal solution checks
divisors only up to √n and adds
both divisors of each factor pair,
reducing the time complexity to
O(√n).

====================================================
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;
        int sum = 0;
        for(int i = 1; i <= num/2; i++) {
            if(num % i == 0)
                sum += i;
        }
        return sum == num;
    }
};
