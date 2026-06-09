# /*

LeetCode Problem: Remove Duplicates from Sorted Array
Problem Number: 26

Approach:

* Since the array is already sorted,
  duplicate elements appear together.

* Use two pointers:

  * One pointer (i) traverses the array.
  * Another pointer (k) keeps track of
    the position for the next unique element.

* Compare current element with the previous:

  * If different:
    place it at index k
    increment k

* Continue until all elements are processed.

Why this approach?

* Sorted arrays naturally group duplicate
  values together, making it efficient to
  overwrite duplicates in-place.

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of elements in the array

====================================================
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1; // first element is always unique
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
