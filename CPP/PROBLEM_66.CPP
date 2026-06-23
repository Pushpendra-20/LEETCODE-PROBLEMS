# /*

LeetCode Problem: Plus One
Problem Number: 66

Approach:

* Start from the last digit of the array.

* Initialize carry = 1 because we need
  to add one to the given number.

* Traverse the digits from right to left:

  * Add carry to the current digit.
  * If the digit becomes greater than 9:

    * Store digit % 10.
    * Keep carry = 1.
  * Otherwise:

    * Set carry = 0 and stop further
      propagation.

* After processing all digits:

  * If carry still exists,
    insert 1 at the beginning of
    the array.

* Return the updated array.

Why this approach?

* Addition starts from the least
  significant digit.
* Carry propagates only when a digit
  becomes 10.

Example:
[1,2,3] → [1,2,4]
[9,9,9] → [1,0,0,0]

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of digits in the array

Key Concepts:

* Array Traversal
* Carry Propagation
* Simulation

====================================================
*/



class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int i=nums.size()-1,carry=1;
        while(carry!=0 && i>=0){
            nums[i]++;
            if(nums[i]>9){
                nums[i]=nums[i]%10;
                carry = 1;
                i--;
            }else{
                carry=0;
            }
        }
        if(carry){
            nums.insert(nums.begin(),1);
        }

        return nums;
    }
};
