/*
====================================================
LeetCode Problem: Container With Most Water
Problem Number: 11

Approach:
- Used Two Pointer Technique
- Initialize two pointers:
    left = 0
    right = n-1

- Calculate area using:
    area = min(height[left], height[right]) 
            * (right-left)

- Store maximum area found.

- Move the pointer having smaller height because:
    a larger height may increase area while width
    keeps decreasing.

Why this approach?
- Brute Force checks all pairs → O(n²)
- Two Pointer approach solves it efficiently → O(n)

Time Complexity: O(n)
Space Complexity: O(1)

====================================================
*/

class Solution {
public:
    int maxArea(vector<int>& nums) {
        int left=0,right=nums.size()-1,max_water=0,area;
        while(left<right){
            area=min(nums[left],nums[right])*(right-left);
            if(area>max_water){
                max_water=area;
            }
            if(nums[left]<nums[right]){
                left+=1;
            }else{
                right-=1;
            }
        }
        return max_water;
    }
};
