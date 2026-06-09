# /*

LeetCode Problem: Remove Element
Problem Number: 27

Approach:

* Traverse through the array using an index.

* Check each element:

  * If current element equals the target
    value:
    remove it using erase().

  * Otherwise:
    move to the next index.

* Continue until all occurrences of the
  target value are removed.

* Return the new size of the array.

Why this approach?

* Elements matching the target value are
  removed directly from the array while
  traversing it.

Time Complexity: O(n²)
Space Complexity: O(1)

Where:
n = number of elements in the array

Note:
Using erase() shifts all subsequent
elements, making this approach less
efficient for large inputs.

====================================================
*/


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
            }else{
                i++;
            }
        }
        return nums.size();
    }
};
