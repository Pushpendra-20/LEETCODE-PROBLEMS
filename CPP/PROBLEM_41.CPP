/*
====================================================
LeetCode Problem: First Missing Positive
Problem Number: 41

Approach:
- Sort the array in ascending order.

- Initialize a variable `missing`
  with 1, since 1 is the smallest
  positive integer.

- Traverse the sorted array:

    - Ignore all non-positive
      numbers (<= 0).

    - If the current element equals
      `missing`, increment `missing`
      to search for the next positive
      integer.

    - If the current element is
      greater than `missing`, then
      `missing` is not present in
      the array and is the answer.

    - Duplicate values are naturally
      ignored because they do not
      affect the value of `missing`.

- If all positive integers up to
  `missing - 1` are found, return
  `missing`.

Why this approach?
- Sorting places all positive numbers
  in ascending order.
- By tracking the smallest expected
  positive integer, we can determine
  the first missing positive while
  traversing the array only once
  after sorting.

Example:

Input:
nums = [1,2,0]

Sorted:
[0,1,2]

Process:
missing = 1
1 found → missing = 2
2 found → missing = 3

Output:
3

Input:
nums = [3,4,-1,1]

Sorted:
[-1,1,3,4]

Process:
missing = 1
1 found → missing = 2
Next positive is 3 (>2)

Output:
2

Input:
nums = [7,8,9,11,12]

Output:
1

Time Complexity: O(n log n)
Space Complexity: O(1)
(or O(log n) depending on the
sorting implementation)

Where:
n = number of elements in the array

Key Concepts:
- Array
- Sorting
- Greedy
- Traversal

Note:
The expected interview solution
runs in O(n) time and O(1) extra
space by placing each positive
integer x at index x-1 using
cyclic placement (index mapping).

====================================================
*/



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int missing = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) {
                continue;
            }
            if (nums[i] == missing) {
                missing++;
            }
            else if (nums[i] > missing) {
                return missing;
            }
        }
        return missing;
    }
};
