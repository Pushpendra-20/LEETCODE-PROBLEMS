# /*

LeetCode Problem: Single Number II
Problem Number: 137

Approach:

* Sort the array in ascending order.

* Traverse the sorted array using
  index `i`.

* Since every element appears exactly
  three times except one:

  * If nums[i] == nums[i + 2],
    then nums[i], nums[i+1], and
    nums[i+2] form a valid triplet.
    Skip all three elements.

  * Otherwise, nums[i] is the unique
    element that appears only once.

* Return the unique element.

Why this approach?

* Sorting groups identical elements
  together.
* Triplets can be skipped efficiently,
  and the first element that does not
  belong to a complete triplet is the
  required answer.

Example:

Input:
nums = [2,2,3,2]

Sorted:
[2,2,2,3]

Output:
3

Input:
nums = [0,1,0,1,0,1,99]

Sorted:
[0,0,0,1,1,1,99]

Output:
99

Time Complexity: O(n log n)
Space Complexity: O(1)
(or O(log n) depending on the sorting implementation)

Where:
n = number of elements in the array

Key Concepts:

* Array
* Sorting
* Traversal

Note:
The optimal solution uses bit
manipulation to achieve O(n) time
and O(1) extra space.

====================================================
*/



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), i = 0;
        sort(nums.begin(), nums.end());
        while (i < n) {
            if (i + 2 < n && nums[i] == nums[i + 2]) {
                i += 3;
            } 
            else {
                return nums[i];
            }
        }
        return nums[n - 1];
    }
};
