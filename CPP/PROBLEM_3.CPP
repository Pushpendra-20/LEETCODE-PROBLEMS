# /*

LeetCode Problem: Longest Substring Without
Repeating Characters
Problem Number: 3

Approach:

* Use Sliding Window technique with
  two pointers:
  left
  right

* Expand the window by moving the
  right pointer.

* For each new character:

  * Check if it already exists
    inside the current window.

* If a duplicate character is found:

  * Move the left pointer forward
    to shrink the window.

* If no duplicate exists:

  * Update the maximum length.

* Continue until the entire string
  is traversed.

Why this approach?

* The sliding window maintains a
  valid substring without repeated
  characters while avoiding repeated
  recalculation.

Time Complexity: O(n²)
Space Complexity: O(1)

Where:
n = length of the string

Note:
This implementation checks duplicates
using a loop inside the window.
Using HashMap/Set optimization can
reduce complexity to O(n).

====================================================
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int max_length = 0;
        while(right < s.size()){
            bool duplicate = false;
            // Check if current character already exists
            // between left and right-1
            for(int i = left; i < right; i++){
                if(s[i] == s[right]){
                    duplicate = true;
                    left++;
                    break;
                }
            }
            if(duplicate == false){
                if(max_length < right - left + 1){
                    max_length = right - left + 1;
                }
                right++;
            }
        }
        return max_length;
    }
};
