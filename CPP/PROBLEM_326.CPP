/*
====================================================
LeetCode Problem: Power of Three
Problem Number: 326

Approach:
- Handle edge cases:
    - If n <= 0, return false.
    - If n == 1, return true since
      3⁰ = 1.

- Initialize a variable `x` to 1.

- Repeatedly multiply x by 3 until:
    - x becomes equal to n, or
    - x becomes greater than n.

- If x equals n at any point,
  return true.

- If the loop ends without finding
  a match, return false.

Why this approach?
- Powers of three follow the
  sequence:
      1, 3, 9, 27, 81, ...

- By generating these values
  iteratively, we can determine
  whether the given number belongs
  to the sequence.

Example:

Input:
n = 27

Sequence:
1 → 3 → 9 → 27

Output:
true

Input:
n = 45

Sequence:
1 → 3 → 9 → 27 → 81

Output:
false

Time Complexity: O(log₃ n)
Space Complexity: O(1)

Where:
n = given integer

Key Concepts:
- Math
- Iteration
- Powers
- Simulation

Note:
The optimal solution avoids looping
by checking whether n is a divisor
of the largest power of 3 that fits
within a 32-bit signed integer:

1162261467 % n == 0

This also runs in O(1) time.

====================================================
*/


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        long long x=1;
        while(x<n){
            x=x*3;
            if(x==n){
                return true;
            }
        }
        return false;
    }
};
