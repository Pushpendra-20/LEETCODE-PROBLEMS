# /*

LeetCode Problem: Search in Rotated Sorted Array
Problem Number: 33

Approach:

* Use Binary Search to efficiently locate
  the target element.

* At each step:

  * Calculate the middle index.
  * If the middle element equals the
    target, return its index.

* Determine which half is sorted:

  1. Left Half Sorted

     * If nums[st] <= nums[mid]
     * Check whether the target lies
       within this range.
     * If yes, search left half.
     * Otherwise, search right half.

  2. Right Half Sorted

     * If nums[mid] <= nums[end]
     * Check whether the target lies
       within this range.
     * If yes, search right half.
     * Otherwise, search left half.

* Continue until the target is found
  or the search space becomes empty.

* Return -1 if the target does not exist.

Why this approach?

* A rotated sorted array always has
  one sorted half.
* Identifying the sorted half allows
  binary search to discard half of
  the remaining elements each step.

Time Complexity: O(log n)
Space Complexity: O(1)

Where:
n = number of elements in the array

====================================================
*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[st] <= nums[mid]){
                if(target >= nums[st] && target < nums[mid]){
                    end = mid - 1;
                }
                else{
                    st = mid + 1;
                }
            }
            else{
                if(target > nums[mid] && target <= nums[end]){
                    st = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        cout << "Index is : -1";
        return -1;
    }
};
