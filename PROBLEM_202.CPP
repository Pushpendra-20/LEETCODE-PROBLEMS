# /*

LeetCode Problem: Happy Number
Problem Number: 202

Approach:

* Repeatedly replace the number with
  the sum of the squares of its digits.

* For each iteration:

  * Extract digits using modulo (%).
  * Compute the sum of their squares.
  * Update the number with this sum.

* If the number becomes 1:

  * Return true because it is a
    Happy Number.

* To detect infinite cycles:

  * Store previously seen values.
  * Before processing a new value,
    check whether it already exists.
  * If it does, a cycle is detected
    and the number is not happy.

Why this approach?

* Happy Numbers eventually reach 1.
* Non-happy numbers enter a repeating
  cycle.
* Tracking visited values allows us
  to identify cycles efficiently.

Example:
n = 19

```
1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1

Output: true
```

Time Complexity: O(log n) per iteration
Space Complexity: O(k)

Where:
k = number of unique values encountered
before reaching 1 or entering a cycle

Key Concepts:

* Math
* Hashing / Cycle Detection
* Digit Manipulation
* Simulation

====================================================
*/




class Solution {
public:
    bool isHappy(int n) {
        int rem=0;
        vector<int> nums;
        if(n==1){
            return true;
        }
        if(n>1){
            while(n!=1){
                int m=0;
                while(n>0){
                    rem = n%10;
                    m = m + rem*rem;
                    n = n/10;
                }
                n = m;
                if(m==1){
                    return true;
                }
                if(find(nums.begin(),nums.end(),n)!=nums.end()){
                    return false;
                }
                nums.push_back(m);
            }
        }
        return false;
    }
};
