# /*

LeetCode Problem: Roman to Integer
Problem Number: 13

Approach:

* Create a helper function to convert
  Roman symbols into their integer values.

* Traverse the string from right to left.

* For each character:

  * Convert the Roman symbol into its
    corresponding integer value.

  * Apply subtraction rule:
    If current value is smaller than
    the value on its right side,
    subtract it from the result.

  * Otherwise:
    add it to the result.

Why this approach?

* Roman numerals follow a subtraction
  pattern such as:
  IV = 4
  IX = 9
  XL = 40

* Traversing from right to left makes it
  easy to decide whether a value should
  be added or subtracted.

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = length of the Roman numeral string

====================================================
*/


class Solution {
public:

    int roman(char symbol) {

        if(symbol == 'I') return 1;
        else if(symbol == 'V') return 5;
        else if(symbol == 'X') return 10;
        else if(symbol == 'L') return 50;
        else if(symbol == 'C') return 100;
        else if(symbol == 'D') return 500;
        else if(symbol == 'M') return 1000;

        return 0;
    }

    int romanToInt(string s) {

        int integer = 0;

        for(int i = s.length() - 1; i >= 0; i--) {

            int current = roman(s[i]);

            // subtraction rule
            if(i < s.length() - 1 && current < roman(s[i + 1])) {
                integer -= current;
            }
            else {
                integer += current;
            }
        }

        return integer;
    }
};
