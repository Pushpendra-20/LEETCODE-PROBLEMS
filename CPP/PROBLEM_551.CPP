/*
====================================================
LeetCode Problem: Student Attendance Record I
Problem Number: 551

Approach:
- Initialize two counters:
    - countA to count the total
      number of absences ('A').
    - countL to count consecutive
      late days ('L').

- Traverse the attendance string
  character by character.

- For each character:

    - If it is 'A':
        - Increment countA.
        - Reset countL since the
          consecutive late streak
          is broken.

    - If it is 'L':
        - Increment countL.

    - Otherwise ('P'):
        - Reset countL because the
          late streak ends.

- After processing each character:
    - If countA becomes 2 or more,
      return false.
    - If countL becomes 3 or more,
      return false.

- If the entire string is processed
  without violating either rule,
  return true.

Why this approach?
- The attendance policy has only
  two conditions:
    - Fewer than 2 absences.
    - No 3 consecutive late days.

- Both conditions can be checked
  in a single traversal using two
  counters, making the solution
  efficient.

Example:

Input:
s = "PPALLP"

Process:
A Count = 1
Maximum Consecutive L = 2

Output:
true

Input:
s = "PPALLL"

Process:
Three consecutive 'L'

Output:
false

Input:
s = "AAP"

Process:
Two absences

Output:
false

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = length of the attendance string

Key Concepts:
- String
- Traversal
- Counting
- Simulation

Note:
This is the optimal solution since
the string is traversed only once
while maintaining constant extra
space.

====================================================
*/



class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0, countL = 0;
        int i = 0;

        while(i < s.size()){

            if(s[i] == 'A'){
                countA++;
                countL = 0;
            }
            else if(s[i] == 'L'){
                countL++;
            }
            else{
                countL = 0;
            }

            if(countA >= 2 || countL >= 3){
                return false;
            }

            i++;
        }

        return true;
    }
};
