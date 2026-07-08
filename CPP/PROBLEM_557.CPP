/*
====================================================
LeetCode Problem: Reverse Words in a String III
Problem Number: 557

Approach:
- Initialize two pointers:
    - st to mark the beginning of
      each word.
    - end to mark the end of the
      current word.

- Traverse the string character
  by character.

- Whenever a space (' ') is found:
    - Set end to the previous
      character.
    - Reverse the current word
      using the two-pointer
      technique.
    - Update st to the beginning
      of the next word.

- After the loop:
    - Reverse the final word,
      since it is not followed
      by a space.

- Return the modified string.

Why this approach?
- Each word is reversed
  independently while preserving
  the original word order.
- The reversal is performed
  in-place, requiring no extra
  string or array.

Example:

Input:
s = "Let's take LeetCode contest"

Processing:
"Let's"     → "s'teL"
"take"      → "ekat"
"LeetCode"  → "edoCteeL"
"contest"   → "tsetnoc"

Output:
"s'teL ekat edoCteeL tsetnoc"

Input:
s = "God Ding"

Output:
"doG gniD"

Time Complexity: O(n)

Space Complexity: O(1)

Where:
n = length of the string

Key Concepts:
- String
- Two Pointers
- In-Place Reversal
- Traversal

Note:
This is an optimal solution since
every character is visited at most
twice (once during traversal and
once during reversal), resulting
in O(n) time and O(1) extra space.

====================================================
*/





class Solution {
public:
    string reverseWords(string s) {
        int st = 0, end = 0, size = s.size();
        for(int i = 0; i < size; i++){
            if(s[i] == ' '){
                end = i - 1;
                while(st < end){
                    swap(s[st], s[end]);
                    st++;
                    end--;
                }
                st = i + 1;
            }
        }
        end = size - 1;
        while(st < end){
            swap(s[st], s[end]);
            st++;
            end--;
        }
        return s;
    }
};
