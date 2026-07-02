/*
====================================================
LeetCode Problem: Find the Duplicate Number
Problem Number: 287

Approach:
- Sort the array in ascending order.

- Initialize two pointers:
    - st at the beginning.
    - end at the end.

- Traverse from both ends
  simultaneously.

- During each iteration:
    - Check if nums[st] equals
      nums[st + 1].
      - If yes, return nums[st].

    - Check if nums[end] equals
      nums[end - 1].
      - If yes, return nums[end].

- Move:
    - st forward.
    - end backward.

- If no duplicate is found,
  return 0.

Why this approach?
- Sorting places duplicate elements
  next to each other.
- Checking adjacent elements from
  both ends allows the duplicate
  value to be identified efficiently.

Example:

Input:
nums = [1,3,4,2,2]

Sorted:
[1,2,2,3,4]

Output:
2

Input:
nums = [3,1,3,4,2]

Sorted:
[1,2,3,3,4]

Output:
3

Time Complexity: O(n log n)
Space Complexity: O(1)
(or O(log n) depending on the
sorting implementation)

Where:
n = number of elements in the array

Key Concepts:
- Array
- Sorting
- Two Pointers
- Adjacent Comparison

Note:
The expected interview solution
uses Floyd's Tortoise and Hare
(Cycle Detection) algorithm,
which runs in O(n) time and
O(1) extra space without
modifying the input array.

====================================================
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size=nums.size();
        int st=0,end=size-1;
        sort(nums.begin(),nums.end());
        while(st<end){
            if(nums[st]==nums[st+1]){
                return nums[st];
            }
            if(nums[end]==nums[end-1]){
                return nums[end];
            }     
            st++;
            end--;      
        }
        return NULL;
    }
};
