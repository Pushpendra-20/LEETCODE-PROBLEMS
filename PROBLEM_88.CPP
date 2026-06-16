# /*

LeetCode Problem: Merge Sorted Array
Problem Number: 88

Approach:

* Use three pointers:
  i -> last valid element in nums1
  j -> last element in nums2
  k -> last position in nums1

* Compare elements from the end of
  both arrays.

* Place the larger element at index k
  and move the corresponding pointer.

* Continue until all elements of nums2
  are merged.

* Since nums1 already has enough space
  to hold all elements, merging from
  the back prevents overwriting
  unprocessed values.

Why this approach?

* Both arrays are already sorted.
* Starting from the end allows in-place
  merging without using extra memory.

Example:
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]

```
Result:
[1,2,2,3,5,6]
```

Time Complexity: O(m + n)
Space Complexity: O(1)

Where:
m = number of valid elements in nums1
n = number of elements in nums2

Key Concepts:

* Two Pointers
* In-Place Array Modification
* Merge Process

====================================================
*/



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(j >= 0) {
            if(i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};
