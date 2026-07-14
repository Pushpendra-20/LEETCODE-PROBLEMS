/*
====================================================
LeetCode Problem: Integer to Roman
Problem Number: 12

Approach:
- Store all Roman numeral values
  along with their corresponding
  symbols in descending order.

- The arrays include both standard
  numerals and subtractive forms:
    - M (1000)
    - CM (900)
    - D (500)
    - CD (400)
    - C (100)
    - XC (90)
    - L (50)
    - XL (40)
    - X (10)
    - IX (9)
    - V (5)
    - IV (4)
    - I (1)

- Traverse the value array from
  largest to smallest.

- While the current value is less
  than or equal to the given number:
    - Append its Roman symbol to
      the answer.
    - Subtract the value from the
      number.

- Continue until the number
  becomes zero.

- Return the constructed Roman
  numeral string.

Why this approach?
- The Roman numeral system is
  based on fixed symbol values.
- Processing values from largest
  to smallest always produces the
  correct Roman numeral.
- Including subtractive forms
  (IV, IX, XL, XC, CD, CM)
  eliminates the need for extra
  conditions.

Example:

Input:
num = 3749

Processing:
3000 → MMM
700  → DCC
40   → XL
9    → IX

Output:
"MMMDCCXLIX"

Input:
num = 58

Output:
"LVIII"

Input:
num = 1994

Output:
"MCMXCIV"

Time Complexity: O(1)

Space Complexity: O(1)

Where:
The Roman numeral system has only
13 possible symbol values, so the
number of iterations is constant.

Key Concepts:
- Greedy Algorithm
- String
- Simulation
- Math

Note:
This is the optimal solution for
the problem. Since the number of
Roman numeral symbols is fixed,
both the time and space complexity
are constant.

====================================================
*/



class Solution {
public:
    string intToRoman(int num) {
        vector<int> value = {
            1000,900,500,400,
            100,90,50,40,
            10,9,5,4,1
        };
        vector<string> symbol = {
            "M","CM","D","CD",
            "C","XC","L","XL",
            "X","IX","V","IV","I"
        };
        string ans = "";
        for(int i = 0; i < value.size(); i++){
            while(num >= value[i]){
                ans += symbol[i];
                num -= value[i];
            }
        }
        return ans;
    }
};
