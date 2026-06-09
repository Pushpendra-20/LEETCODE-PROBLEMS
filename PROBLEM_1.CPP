# /*

LeetCode Problem: Two Sum
Problem Number: 1

Approach:

* Use two nested loops to check every
  possible pair of elements.

* For each element:

  * Traverse remaining elements.
  * Check whether the sum of the pair
    equals the target value.

* If the target sum is found:

  * Return the indices of both elements.

Why this approach?

* Brute force ensures every possible
  combination is checked and guarantees
  finding the correct pair.

Time Complexity: O(n²)
Space Complexity: O(1)

Where:
n = number of elements in the array

====================================================
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
