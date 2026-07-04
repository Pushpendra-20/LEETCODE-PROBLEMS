/*
====================================================
LeetCode Problem: Reverse Vowels of a String
Problem Number: 345

Approach:
- Create a helper function
  `isVowel()` to check whether a
  character is a vowel.
  - Convert the character to
    lowercase.
  - Return true if it is one of:
    a, e, i, o, or u.

- Initialize two pointers:
    - left at the beginning.
    - right at the end.

- Traverse while left < right.

- If both characters are vowels:
    - Swap them.
    - Move both pointers inward.

- If only the left character is a
  vowel:
    - Move the right pointer left.

- If only the right character is a
  vowel:
    - Move the left pointer right.

- If neither character is a vowel:
    - Move both pointers inward.

- Continue until the pointers meet.

- Return the modified string.

Why this approach?
- The two-pointer technique allows
  vowels to be swapped directly
  without affecting consonants.
- Each character is visited at most
  once, making the solution highly
  efficient.

Example:

Input:
s = "IceCreAm"

Vowels:
I, e, e, A

After Reversal:
AceCreIm

Output:
"AceCreIm"

Input:
s = "hello"

Output:
"holle"

Input:
s = "leetcode"

Output:
"leotcede"

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = length of the string

Key Concepts:
- String
- Two Pointers
- Character Manipulation
- In-Place Swapping

Note:
This is the optimal solution for
the problem. It reverses only the
vowels while leaving all other
characters unchanged, achieving
O(n) time and O(1) extra space.

====================================================
*/


class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        int size = s.size();
        int left = 0, right = size - 1;

        while(left < right){

            if(isVowel(s[left]) && isVowel(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if(isVowel(s[left]) && !isVowel(s[right])){
                right--;
            }
            else if(!isVowel(s[left]) && isVowel(s[right])){
                left++;
            }
            else{
                left++;
                right--;
            }
        }

        return s;
    }
};
