# /*

LeetCode Problem: Reverse Integer
Problem Number: 7

Approach:

* Extract digits one by one using
  modulo operator (%).

* Store the last digit:
  rem = x % 10

* Build the reversed number:
  num = num * 10 + rem

* Before updating the number,
  check for integer overflow:

  * If num exceeds INT_MAX/10
  * Or becomes smaller than INT_MIN/10
    return 0.

* Continue until the original number
  becomes 0.

Why this approach?

* Digits are processed individually,
  allowing reversal without converting
  the integer into a string.
* Overflow handling ensures the result
  remains within the 32-bit integer range.

Time Complexity: O(log₁₀ n)
Space Complexity: O(1)

Where:
n = value of the integer

====================================================
*/



class Solution {
public:
    int reverse(int x) {
        int rem = 0;
        int num = 0;
        while(x != 0) {
            rem = x % 10;
            // Overflow check
            if(num > INT_MAX/10 || num < INT_MIN/10) {
                return 0;
            }
            num = num * 10 + rem;
            x = x / 10;
        }
        return num;
    }
};
