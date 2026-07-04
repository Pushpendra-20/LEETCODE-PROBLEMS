/*
====================================================
LeetCode Problem: Power of Four
Problem Number: 342

Approach:
- Handle edge cases:
    - If n <= 0, return false.
    - If n == 1, return true since
      4⁰ = 1.

- Initialize a variable `x` to 1.

- Repeatedly multiply x by 4 until:
    - x becomes equal to n, or
    - x becomes greater than n.

- If x equals n at any point,
  return true.

- Otherwise, return false.

Why this approach?
- Powers of four follow the
  sequence:
      1, 4, 16, 64, 256, ...

- By generating these values
  iteratively, we can easily check
  whether the given number is a
  power of four.

Example:

Input:
n = 16

Sequence:
1 → 4 → 16

Output:
true

Input:
n = 8

Sequence:
1 → 4 → 16

Output:
false

Input:
n = 1

Output:
true

Time Complexity: O(log₄ n)
Space Complexity: O(1)

Where:
n = given integer

Key Concepts:
- Math
- Iteration
- Powers
- Simulation

Note:
The optimal solution uses bit
manipulation:

    n > 0 &&
    (n & (n - 1)) == 0 &&
    (n & 0x55555555) != 0

This works because a power of four
has exactly one set bit, and that
bit always appears in an odd
position (0, 2, 4, ...).

====================================================
*/



class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        long long x=1;
        while(x<n){
            x=x*4;
            if(x==n){
                return true;
            }
        }
        return false;
    }
};
