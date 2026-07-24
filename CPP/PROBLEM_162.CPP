/*
====================================================
LeetCode Problem: Find Peak Element
Problem Number: 162

Approach:
- Use Binary Search to locate a
  peak element.

- Initialize:
    - st = 0
    - end = n - 1

- While st < end:
    - Compute the middle index.

    - Compare nums[mid] with
      nums[mid + 1].

    - If nums[mid] < nums[mid + 1]:
        - The slope is increasing.
        - A peak must exist on the
          right side.
        - Move st = mid + 1.

    - Otherwise:
        - The slope is decreasing
          or mid itself may be a
          peak.
        - Move end = mid.

- When st == end:
    - Both pointers point to a
      peak element.

- Return st.

Why this approach?
- Instead of checking every
  element, Binary Search uses the
  slope of the array to eliminate
  half of the remaining search
  space after every iteration.
- Since the problem guarantees
  that a peak always exists, the
  search always converges to one.

Example:

Input:
nums = [1,2,3,1]

Process:

mid = 1
2 < 3
Search Right

mid = 2
3 > 1
Search Left

Output:
2

Input:
nums = [1,2,1,3,5,6,4]

Possible Output:
5

(Time Complexity allows returning
any valid peak.)

Time Complexity: O(log n)

Space Complexity: O(1)

Where:
n = number of elements in the
array

Key Concepts:
- Array
- Binary Search
- Divide and Conquer

Note:
This is the optimal solution.
Rather than searching linearly,
it leverages the increasing or
decreasing slope of the array to
discard half of the search space
in every iteration.

====================================================
*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;

        while(st < end){
            int mid = st + (end - st) / 2;

            if(nums[mid] < nums[mid + 1]){
                st = mid + 1;
            }
            else{
                end = mid;
            }
        }

        return st;
    }
};
