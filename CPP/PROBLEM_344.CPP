/*
====================================================
LeetCode Problem: Reverse String
Problem Number: 344

Approach:
- Initialize two pointers:
    - left at the beginning of the
      character array.
    - right at the end of the array.

- Traverse while left < right.

- Swap the characters at the
  left and right pointers.

- Move:
    - left one step forward.
    - right one step backward.

- Continue until both pointers
  meet or cross each other.

- The character array is reversed
  in-place without using extra space.

Why this approach?
- The two-pointer technique swaps
  characters from both ends of the
  array simultaneously.
- Since the reversal is performed
  in-place, no additional array is
  required.

Example:

Input:
s = ['h','e','l','l','o']

After Swaps:
['o','l','l','e','h']

Output:
['o','l','l','e','h']

Input:
s = ['H','a','n','n','a','h']

Output:
['h','a','n','n','a','H']

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of characters

Key Concepts:
- String
- Two Pointers
- In-Place Swapping

Note:
This is the optimal solution for
the problem since it reverses the
string directly in-place without
using any extra memory.

====================================================
*/


class Solution {
public:
    void reverseString(vector<char>& s) {
        int size=s.size();
        int left=0,right=size-1;
        while(left<right){
            int temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }
    }
};
