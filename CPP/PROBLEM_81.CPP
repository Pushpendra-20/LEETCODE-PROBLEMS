# /*

LeetCode Problem: Search in Rotated Sorted Array II
Problem Number: 81

Approach:

* Initialize two pointers:

  * st (start)
  * end (end)

* Perform Binary Search while
  st <= end.

* Compute the middle index.

* If the target is found at mid,
  return true.

* Handle duplicate elements:

  * If nums[st] == nums[mid] ==
    nums[end], it is impossible to
    determine the sorted half.
  * Shrink the search space by
    incrementing st and decrementing
    end.

* Otherwise:

  * Check whether the left half is
    sorted.
  * If the target lies within the
    sorted left half, search there.
  * Otherwise, search the right half.

* If the right half is sorted:

  * Check whether the target lies
    within that range.
  * Search accordingly.

* If the loop finishes without
  finding the target, return false.

Why this approach?

* A rotated sorted array still has
  at least one sorted half.
* Binary Search efficiently narrows
  the search space.
* Handling duplicates separately
  avoids ambiguity when determining
  the sorted portion.

Example:

Input:
nums = [2,5,6,0,0,1,2]
target = 0

Output:
true

Input:
nums = [2,5,6,0,0,1,2]
target = 3

Output:
false

Time Complexity:

* Average: O(log n)
* Worst Case: O(n)
  (when many duplicate elements exist)

Space Complexity: O(1)

Where:
n = number of elements in the array

Key Concepts:

* Binary Search
* Rotated Sorted Array
* Duplicate Handling
* Divide and Conquer

====================================================
*/




class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
            }
            else if (nums[st] <= nums[mid]) {
                if (target >= nums[st] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }else {
                if (target > nums[mid] && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
