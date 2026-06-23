# /*

LeetCode Problem: Length of Last Word
Problem Number: 58

Approach:

* Start traversing the string from the end.

* First, skip all trailing spaces.
  This ensures we reach the actual
  last word.

* Once a character of the last word
  is found:

  * Count characters until a space
    or the beginning of the string
    is reached.

* Return the count as the length of
  the last word.

Why this approach?

* Traversing from the end avoids
  processing unnecessary words and
  directly targets the last word.

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = length of the string

====================================================
*/


class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int count = 0;
        // Skip trailing spaces
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        // Count characters of last word
        while(i >= 0 && s[i] != ' '){
            count++;
            i--;
        }
        return count;
    }
};
