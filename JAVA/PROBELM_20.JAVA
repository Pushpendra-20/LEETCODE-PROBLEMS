# /*

LeetCode Problem: Valid Parentheses
Problem Number: 20

Approach:

* Continuously remove valid pairs of
  parentheses from the string.

* Check for:
  ()
  {}
  []

* If any valid pair exists:

  * Remove it using replace().
  * Repeat the process.

* Continue until no more valid pairs
  can be found.

* If the resulting string becomes
  empty:

  * All brackets were matched
    correctly.
  * Return true.

* Otherwise:

  * Some unmatched brackets remain.
  * Return false.

Why this approach?

* Every valid parentheses string can
  eventually be reduced to an empty
  string by repeatedly removing valid
  bracket pairs.

Example:

Input:
"()[]{}"

Process:
"()[]{}"
→ "[]{}"
→ "{}"
→ ""

Output:
true

Input:
"(]"

Output:
false

Time Complexity: O(n²)
Space Complexity: O(n)

Where:
n = length of the string

Key Concepts:

* String Manipulation
* Simulation
* Parentheses Matching

Note:
A stack-based solution achieves
O(n) time complexity and is the
optimal interview approach.

====================================================
*/



class Solution {
    public boolean isValid(String s) {
        while (true) {
            if (s.contains("()")) {
                s = s.replace("()", "");
            } else if (s.contains("{}")) {
                s = s.replace("{}", "");
            } else if (s.contains("[]")) {
                s = s.replace("[]", "");
            } else {
                return s.isEmpty();
            }
        }
    }
}
