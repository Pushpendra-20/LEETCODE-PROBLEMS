# /*

LeetCode Problem: Single Number
Problem Number: 136

Approach:

* Initialize a variable `result` to 0.

* Traverse the array once.

* For each element:

  * Perform the XOR (^) operation
    between `result` and the current
    element.

* Return the final value of `result`.

Why this approach?

* XOR has the following properties:

  * a ^ a = 0
  * a ^ 0 = a
  * XOR is commutative and associative

* Since every element appears twice
  except one, all duplicate elements
  cancel each other out, leaving only
  the unique element.

Example:

Input:
nums = [4,1,2,1,2]

Process:
0 ^ 4 = 4
4 ^ 1 = 5
5 ^ 2 = 7
7 ^ 1 = 6
6 ^ 2 = 4

Output:
4

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of elements in the array

Key Concepts:

* Bit Manipulation
* XOR
* Array Traversal

====================================================
*/


Class Solution{
public:
  int SingleNumber(vector<int> nums){
    int result=0;
    for(int i=0;i<nums.size();i++){
      result ^= nums[i];
    }
    return result;
  }
};
