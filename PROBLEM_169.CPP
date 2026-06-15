# /*

LeetCode Problem: Majority Element
Problem Number: 169

Approach:

* Use a brute-force approach to find
  the majority element.

* For each element in the array:

  * Count how many times it appears
    in the entire array.

* If the count becomes greater than
  n / 2:

  * Return that element as the
    majority element.

* Since the problem guarantees that
  a majority element always exists,
  one of the elements will satisfy
  this condition.

Why this approach?

* By checking the frequency of every
  element, we can directly determine
  whether it appears more than half
  of the total array size.

Example:
Input: [3,2,3]
Output: 3

```
Input: [2,2,1,1,1,2,2]
Output: 2
```

Time Complexity: O(n²)
Space Complexity: O(1)

Where:
n = number of elements in the array

Key Concepts:

* Array Traversal
* Frequency Counting
* Brute Force

====================================================
*/



class Solution {
public:
    int majorityElement(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    count +=1;
                }
            }      
            if(count > nums.size()/2){
                return nums[i];
                break;
            }      
        }
        return 0;
    }
};
