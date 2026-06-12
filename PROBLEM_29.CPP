# /*

LeetCode Problem: Divide Two Integers
Problem Number: 29

Approach:

* Handle the special overflow case:
  INT_MIN / -1
  which exceeds the 32-bit integer range.

* Convert both dividend and divisor
  to positive long long values to
  safely perform calculations.

* Use repeated doubling to speed up
  division:

  * Start with divisor.
  * Keep doubling it until it becomes
    the largest possible multiple
    less than or equal to the dividend.
  * Subtract this value from the
    dividend.
  * Add the corresponding multiple
    to the quotient.

* Repeat until the remaining dividend
  becomes smaller than the divisor.

* Determine the final sign:

  * Negative if exactly one of
    dividend or divisor is negative.
  * Positive otherwise.

Why this approach?

* Direct use of multiplication,
  division, and modulo operators is
  not allowed.
* Repeated doubling significantly
  reduces the number of operations
  compared to repeated subtraction.

Time Complexity: O(log² n)
Space Complexity: O(1)

Where:
n = absolute value of the dividend

Key Concepts:

* Overflow Handling
* Bit Manipulation Style Doubling
* Efficient Division without using
  '/' operator

====================================================
*/




class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long quotient = 0;

        while (dvd >= dvs) {

            long long temp = dvs;
            long long multiple = 1;

            while (dvd >= temp + temp) {
                temp = temp + temp;
                multiple = multiple + multiple;
            }

            dvd -= temp;
            quotient += multiple;
        }

        if ((dividend < 0) ^ (divisor < 0))
            quotient = -quotient;

        return (int)quotient;
    }
};
