/*
====================================================
LeetCode Problem: Find Minimum in Rotated Sorted Array
Problem Number: 153

Approach:
- Initialize two pointers:
    - st (start)
    - end (end)

- Perform Binary Search while
  st < end.

- Compute the middle index.

- Compare nums[mid] with nums[end]:

    - If nums[mid] > nums[end]:
        - The minimum element lies
          in the right half.
        - Move st to mid + 1.

    - Otherwise:
        - The minimum element lies
          in the left half,
          including mid.
        - Move end to mid.

- When st == end, both pointers
  point to the minimum element.

- Return nums[st].

Why this approach?
- In a rotated sorted array without
  duplicates, one half is always
  sorted.
- Comparing the middle element with
  the last element identifies which
  half contains the minimum.
- Binary Search reduces the search
  space by half in each iteration.

Example:

Input:
nums = [3,4,5,1,2]

Output:
1

Input:
nums = [4,5,6,7,0,1,2]

Output:
0

Input:
nums = [11,13,15,17]

Output:
11

Time Complexity: O(log n)
Space Complexity: O(1)

Where:
n = number of elements in the array

Key Concepts:
- Binary Search
- Rotated Sorted Array
- Divide and Conquer

====================================================
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] > nums[end]) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[st];
    }
};
