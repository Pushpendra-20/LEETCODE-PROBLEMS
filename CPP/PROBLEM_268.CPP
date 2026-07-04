/*
====================================================
LeetCode Problem: Missing Number
Problem Number: 268

Approach:
- Sort the array in ascending order.

- Traverse the sorted array from
  index 0 to n - 1.

- For each index:
    - Compare the current index with
      the value at that index.

- If they are different:
    - The current index represents
      the missing number.
    - Return that index immediately.

- If all indices match their values,
  then the missing number is n,
  which is returned after the loop.

Why this approach?
- In a sorted array containing
  numbers from 0 to n, every element
  should match its index except for
  the missing number.
- The first mismatch directly
  identifies the missing value.

Example:

Input:
nums = [3,0,1]

Sorted:
[0,1,3]

Comparison:
Index 0 → 0 ✓
Index 1 → 1 ✓
Index 2 → 3 ✗

Output:
2

Input:
nums = [0,1]

Sorted:
[0,1]

Output:
2

Time Complexity: O(n log n)
Space Complexity: O(1)
(or O(log n) depending on the
sorting implementation)

Where:
n = number of elements in the array

Key Concepts:
- Array
- Sorting
- Index Comparison

Note:
The optimal solutions are:
1. Sum Formula:
   Expected Sum - Actual Sum
   Time: O(n), Space: O(1)

2. XOR Technique:
   XOR all indices and elements.
   Time: O(n), Space: O(1)

====================================================
*/



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<size;i++){
            if(i!=nums[i]){
                return i;
            }
        }
        return size;
    }
};
