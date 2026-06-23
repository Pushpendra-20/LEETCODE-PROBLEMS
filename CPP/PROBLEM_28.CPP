# /*

LeetCode Problem: Find the Index of the First
Occurrence in a String
Problem Number: 28

Approach:

* First check whether the length of the
  haystack is smaller than the needle.
  If yes, return -1.

* Traverse through the haystack string.

* For each starting position:

  * Compare characters of the needle
    one by one.
  * If all characters match,
    return the starting index.

* If no complete match is found,
  return -1.

Why this approach?

* We compare every possible starting
  position in the string and stop as soon
  as a complete match is found.

Time Complexity: O((n-m+1) × m)
Space Complexity: O(1)

Where:
n = length of haystack
m = length of needle

====================================================
*/



class Solution {
public:
    int strStr(string haystack, string needle) {
        bool found = false;
        if(haystack.size()<needle.size()){
            return -1;
        }
        for(int i=0;i<=haystack.size()-needle.size();i++){
            found = true;
            for(int j=0;j<needle.size();j++){
                if(haystack[i+j]!=needle[j]){
                    found = false;
                    break;
                }
            }
            if(found){
                return i;
            }
        }
        return -1;
    }
};
