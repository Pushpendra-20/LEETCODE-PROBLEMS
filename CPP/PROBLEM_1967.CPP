/*
====================================================
LeetCode Problem: Number of Strings That Appear as Substrings in Word
Problem Number: 1967

Approach:
- Initialize a counter to 0.

- Traverse each string in the
  patterns array.

- For every pattern:
    - Check whether it appears as
      a substring of the given word
      using the contains() function.

- If the pattern exists in the word:
    - Increment the counter.

- After checking all patterns,
  return the total count.

Why this approach?
- Each pattern is checked
  independently.
- The built-in contains() function
  efficiently determines whether a
  substring exists within the word.
- The solution is simple, readable,
  and satisfies the problem
  requirements.

Example:

Input:
patterns = ["a","abc","bc","d"]
word = "abc"

Checking:
"a"   → Found
"abc" → Found
"bc"  → Found
"d"   → Not Found

Output:
3

Time Complexity: O(n × m)

Where:
n = number of patterns
m = average length of each substring
search (depends on the implementation
of contains())

Space Complexity: O(1)

Key Concepts:
- Strings
- Substrings
- String Matching
- Traversal

====================================================
*/



class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(int i=0;i<patterns.size();i++){
            if(word.contains(patterns[i])){
                count++;
            }
        }
        return count;
    }
};
