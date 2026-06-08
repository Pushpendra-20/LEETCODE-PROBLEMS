# /*

LeetCode Problem: Longest Common Prefix
Problem Number: 14

Approach:

* Take the first string as a reference.

* Traverse each character of the first string.

* For every character:

  * Compare it with the same position
    in all other strings.
  * If a mismatch occurs or the current
    index exceeds any string length,
    stop the process.

* If all strings contain the same character
  at that position, add it to the answer.

Why this approach?

* The common prefix must exist in all strings.
* Using the first string as a reference avoids
  unnecessary comparisons.

Time Complexity: O(n × m)
Space Complexity: O(1)

Where:
n = number of strings
m = length of the shortest string

====================================================
*/




class Solution {
public:
    string longestCommonPrefix(vector<string>& nums) {
        int j=0;
        string ans;
        while(j<nums[0].size()){
            bool match = true;
            char current = nums[0][j];
            for(int i=0;i<nums.size();i++){
                if(j >= nums[i].size() || nums[i][j] != current){
                    match = false;
                    break;
                }
            }
            if(match){
                ans.push_back(current);
                j++;
            }else{
                break;
            }
        }
        return ans;
    }
};
