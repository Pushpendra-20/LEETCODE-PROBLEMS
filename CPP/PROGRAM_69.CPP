# /*

LeetCode Problem: Sqrt(x)
Problem Number: 69

Approach:

* Handle edge cases:

  * If x is 0 or 1, return x directly.

* Traverse numbers starting from 1.

* For each number i:

  * Check if i * i equals x.

    * If yes, return i.
  * Check if i * i becomes greater than x.

    * If yes, return i - 1.

* Use long long to prevent overflow
  when calculating i * i.

Why this approach?

* The square root of a number is the
  largest integer whose square is less
  than or equal to the given number.

* By checking squares sequentially,
  we can determine the integer square root.

Example:
x = 4  → 2
x = 8  → 2

Time Complexity: O(√n)
Space Complexity: O(1)

Where:
n = value of x

Key Concepts:

* Math
* Iteration
* Overflow Handling

====================================================
*/



class Solution {
public:
    int mySqrt(int x) {

        if(x == 0 || x == 1){
            return x;
        }

        for(long long i = 1; i <= x; i++){

            if(i * i > x){
                return i - 1;
            }

            if(i * i == x){
                return i;
            }
        }

        return 0;
    }
};
