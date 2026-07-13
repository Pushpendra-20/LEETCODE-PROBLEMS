/*
====================================================
LeetCode Problem: 3Sum
Problem Number: 15

Approach:
- Sort the array in ascending order.

- Traverse the array using index i
  as the first element of the triplet.

- Skip duplicate values for i to
  avoid duplicate triplets.

- Initialize two pointers:
    - left = i + 1
    - right = n - 1

- While left < right:
    - Calculate the sum of
      nums[i], nums[left], and
      nums[right].

    - If the sum is 0:
        - Store the triplet.
        - Skip duplicate values
          for both pointers.
        - Move both pointers
          inward.

    - If the sum is less than 0:
        - Move the left pointer
          right to increase the sum.

    - If the sum is greater than 0:
        - Move the right pointer
          left to decrease the sum.

- Continue until all possible
  triplets have been checked.

- Return the list of unique
  triplets.

Why this approach?
- Sorting enables the efficient
  use of the Two-Pointer technique.
- Duplicate triplets are avoided by
  skipping repeated values.
- The algorithm examines each
  possible first element while
  searching the remaining array
  efficiently.

Example:

Input:
nums = [-1,0,1,2,-1,-4]

Sorted:
[-4,-1,-1,0,1,2]

Output:
[
  [-1,-1,2],
  [-1,0,1]
]

Input:
nums = [0,1,1]

Output:
[]

Input:
nums = [0,0,0]

Output:
[[0,0,0]]

Time Complexity: O(n²)

Space Complexity: O(1)
(excluding the output list)

Where:
n = number of elements in the array

Key Concepts:
- Array
- Sorting
- Two Pointers
- Duplicate Handling

Note:
This is the optimal solution for
the problem. Sorting combined with
the Two-Pointer technique reduces
the brute-force O(n³) solution to
O(n²) while ensuring only unique
triplets are returned.

====================================================
*/




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return ans;
    }
};
