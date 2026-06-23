# /*

LeetCode Problem: Find First and Last Position
of Element in Sorted Array
Problem Number: 34

Approach:

* Since the array is sorted, use
  Binary Search to efficiently find
  the target's boundaries.

* Perform two separate binary searches:

  1. Left Boundary Search

     * When target is found,
       store its index.
     * Continue searching in the
       left half to find the first
       occurrence.


  2. Right Boundary Search

     * When target is found,
       store its index.
     * Continue searching in the
       right half to find the last
       occurrence.

* Return both indices as:
  {first_position, last_position}

* If the target is not found,
  return {-1, -1}.

Why this approach?

* A single binary search finds only
  one occurrence of the target.
* Two binary searches allow us to
  determine the exact range while
  maintaining logarithmic complexity.

Time Complexity: O(log n)
Space Complexity: O(1)

Where:
n = number of elements in the array

====================================================
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1, right = -1;

        // left boundary
        int st = 0, end = nums.size() - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(target == nums[mid]){
                left = mid;
                end = mid - 1;  // rukko mat, aur left jao
            }else if(nums[mid] < target){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        // right boundary
        st = 0; end = nums.size() - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(target == nums[mid]){
                right = mid;
                st = mid + 1;   // rukko mat, aur right jao
            }else if(nums[mid] < target){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        return {left, right};
    }
};
