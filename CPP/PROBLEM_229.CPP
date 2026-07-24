/*
====================================================
LeetCode Problem: Majority Element II
Problem Number: 229

Approach:
- Use an unordered_map to store
  the frequency of each element.

- Traverse the array:
    - Increment the frequency of
      each number in the hash map.

- Traverse the hash map:
    - If the frequency of an
      element is greater than
      n / 3, add it to the answer
      vector.

- Return the resulting vector.

Why this approach?
- A hash map efficiently counts
  the occurrences of every unique
  element.
- After counting frequencies,
  identifying elements appearing
  more than n/3 times is
  straightforward.

Example:

Input:
nums = [3,2,3]

Frequency:
3 → 2
2 → 1

Threshold:
n / 3 = 1

Output:
[3]

Input:
nums = [1]

Output:
[1]

Input:
nums = [1,2]

Output:
[1,2]

Input:
nums = [1,1,1,3,3,2,2,2]

Frequency:
1 → 3
2 → 3
3 → 2

Threshold:
8 / 3 = 2

Output:
[1,2]

Time Complexity: O(n)

Space Complexity: O(n)

Where:
n = number of elements in the
array

Key Concepts:
- Array
- Hash Map
- Frequency Counting

Note:
This solution is simple and
efficient, using extra space for
frequency counting.

The optimal interview solution is
the Boyer-Moore Voting Algorithm,
which achieves:
- Time Complexity: O(n)
- Space Complexity: O(1)

====================================================
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();

        for(int x : nums){
            mp[x]++;
        }

        for(auto it : mp){
            if(it.second > n / 3){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
