/*
====================================================
LeetCode Problem: Palindrome Number
Problem Number: 9

Approach:
- Convert the integer into a string using to_string().
- Initialize two pointers:
    left = 0
    right = length - 1

- Compare characters from both ends:
    - If both characters match:
        move left forward
        move right backward
    - If characters do not match:
        the number is not a palindrome.

- Continue until left >= right.

Why this approach?
- A palindrome reads the same from left to right
  and right to left.
- Two pointer technique efficiently checks
  matching digits from both ends.

Time Complexity: O(n)
Space Complexity: O(n)

Where:
n = number of digits in the integer

====================================================
*/


class Solution {
public:
    bool isPalindrome(int x) {
        string y = to_string(x);
        int left=0,right=y.length()-1,is_palindrom=0;
        while(left<right){
            if(y[left]==y[right]){
                left+=1;
                right-=1;
            }else{
                is_palindrom = 1;
                break;
            }
        }
        if(is_palindrom==1){
            return false;
        }else{
            return true;
        }
    }
};
