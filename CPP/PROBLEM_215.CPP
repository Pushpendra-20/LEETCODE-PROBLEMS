# /*

LeetCode Problem: Kth Largest Element in an Array
Problem Number: 215

Approach:

* Handle the edge case where k is 0.

* Sort the array in ascending order
  using the built-in sort() function.

* Since the array is sorted:

  * The largest element is at the
    last index.
  * The k-th largest element is at:
    nums.size() - k

* Return the element at that index.

Why this approach?

* Sorting arranges all elements in
  ascending order, making it easy to
  locate the k-th largest element
  directly by index.

Example:

Input:
nums = [3,2,1,5,6,4]
k = 2

Sorted Array:
[1,2,3,4,5,6]

Output:
5

Input:
nums = [3,2,3,1,2,4,5,5,6]
k = 4

Sorted Array:
[1,2,2,3,3,4,5,5,6]

Output:
4

Time Complexity: O(n log n)
Space Complexity: O(1)
(or O(log n) due to the sorting algorithm's recursion stack)

Where:
n = number of elements in the array

Key Concepts:

* Array
* Sorting
* Indexing

====================================================
*/




class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k==0){
            return 0;
        }
        vector<int> nums1;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
