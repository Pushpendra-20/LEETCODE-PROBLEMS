/*
====================================================
LeetCode Problem: Third Maximum Number
Problem Number: 414

Approach:
- Sort the array in ascending order.

- Initialize:
    - i at the last index.
    - count = 1 since the largest
      element is the first distinct
      maximum.
    - x as the largest element.

- Traverse the array from right
  to left.

- Whenever the current element
  differs from the previous one:
    - Increment the distinct count.
    - Update x with the new
      distinct maximum.

- If the distinct count reaches 3:
    - Return x as the third
      maximum number.

- If fewer than three distinct
  numbers exist:
    - Return the maximum element.

Why this approach?
- Sorting places duplicate values
  together.
- Traversing from the end allows
  counting distinct maximum values
  efficiently.
- If three distinct values are not
  found, the largest element is
  returned as required.

Example:

Input:
nums = [3,2,1]

Sorted:
[1,2,3]

Distinct Maximums:
3 (1st)
2 (2nd)
1 (3rd)

Output:
1

Input:
nums = [1,2]

Output:
2

Input:
nums = [2,2,3,1]

Sorted:
[1,2,2,3]

Distinct Maximums:
3 (1st)
2 (2nd)
1 (3rd)

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
- Distinct Elements
- Traversal

Note:
The optimal solution solves the
problem in O(n) time and O(1)
extra space by maintaining the
first, second, and third distinct
maximum values while traversing
the array only once.

====================================================
*/


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int size=nums.size(),i=size-1,count=1,x=nums[size-1];
        sort(nums.begin(),nums.end());
        while(i>0){
            if(nums[i]!=nums[i-1]){
                count++;
                x=nums[i-1];
            }
            if(count==3) return x;
            i--;
        }
        return nums[size-1];
    }
};
