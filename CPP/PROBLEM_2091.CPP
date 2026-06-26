# /*

LeetCode Problem: Removing Minimum and Maximum From Array
Problem Number: 2091

Approach:

* Traverse the array once to find the
  indices of the minimum and maximum
  elements.

* Consider four possible ways to
  remove both elements:

  1. Remove both from the front.
  2. Remove both from the back.
  3. Remove the minimum from the front
     and the maximum from the back.
  4. Remove the maximum from the front
     and the minimum from the back.

* Compute the number of deletions
  required for each strategy.

* Return the minimum among all four
  possibilities.

Why this approach?

* Since deletions are allowed only
  from the beginning or the end,
  evaluating all possible deletion
  strategies guarantees the minimum
  number of operations.

Example:

Input:
nums = [2,10,7,5,4,1,8,6]

Minimum = 1
Maximum = 10

Output:
5

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of elements in the array

Key Concepts:

* Array
* Greedy
* Index Manipulation
* Simulation

====================================================
*/




Class Solution{
public:
  int minimumDeletions(vector<int> &nums){
    int n = nums.size();
    int min_idx=0,max_idx=0;
    for(int i=0;i<n;i++){
      if(nums[min_idx]>nums[i]){
        min_idx=i;
      }
      if(nums[max_idx]<nums[i]){
        max_idx=i;
      }
    }
    int front=max(min_idx,max_idx)+1;
    int back=n-min(min_idx,max_idx);
    int mixed1=(min_idx+1)+(n-max_idx);
    int mixed2(max_idx +1)+(n-min_idx);
    int ans=min(front,min(back,min(mixed1,mixed2)));
    return ans;
}
