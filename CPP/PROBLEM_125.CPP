/*
====================================================
LeetCode Problem: Valid Palindrome
Problem Number: 125

Approach:
- Initialize two pointers:
    - i at the beginning of the string.
    - j at the end of the string.

- Traverse the string while
  i < j.

- Skip all non-alphanumeric
  characters using isalnum().

- Compare the characters after
  converting both to lowercase
  using tolower().

- If the characters do not match:
    - Return false immediately.

- Otherwise:
    - Move both pointers towards
      the center.

- If the entire string is processed
  without any mismatch, return true.

Why this approach?
- The problem requires ignoring
  spaces, punctuation, and letter
  casing.
- Using the two-pointer technique
  allows checking the palindrome
  efficiently in a single traversal
  without creating a new string.

Example:

Input:
s = "A man, a plan, a canal: Panama"

Processed String:
"amanaplanacanalpanama"

Output:
true

Input:
s = "race a car"

Output:
false

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = length of the string

Key Concepts:
- Two Pointers
- String
- Character Processing
- Palindrome Checking

====================================================
*/



class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
