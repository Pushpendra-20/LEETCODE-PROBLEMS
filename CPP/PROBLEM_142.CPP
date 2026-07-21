/*
====================================================
LeetCode Problem: Linked List Cycle II
Problem Number: 142

Approach:
- Use Floyd's Cycle Detection
  Algorithm (Tortoise and Hare).

- Initialize two pointers:
    - slow moves one step.
    - fast moves two steps.

- Traverse the linked list until:
    - fast reaches the end
      (no cycle), or
    - slow and fast meet
      (cycle detected).

- If no cycle exists:
    - Return nullptr.

- If a cycle is detected:
    - Move one pointer back to
      the head of the list.
    - Keep the other pointer at
      the meeting point.

- Move both pointers one step at
  a time.

- The node where they meet again
  is the starting node of the
  cycle.

- Return that node.

Why this approach?
- Floyd's algorithm detects a
  cycle without using extra
  memory.
- After the first meeting,
  mathematical properties of the
  cycle guarantee that moving one
  pointer from the head and the
  other from the meeting point
  will make them meet exactly at
  the cycle's starting node.

Example:

Input:

3 → 2 → 0 → -4
    ↑         |
    └─────────┘

Output:
Node with value 2

Input:

1 → 2
No cycle

Output:
nullptr

Time Complexity: O(n)

Space Complexity: O(1)

Where:
n = number of nodes in the
linked list

Key Concepts:
- Linked List
- Fast & Slow Pointers
- Floyd's Cycle Detection
- Two Pointers

Note:
This is the optimal solution.
It detects the presence of a
cycle and finds its starting
node using constant extra space.

====================================================
*/



class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return nullptr;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(temp2 != NULL && temp2->next != NULL){
            temp1 = temp1->next;
            temp2 = temp2->next->next;
            if(temp1 == temp2){
                temp1 = head;   // Move one pointer back to head
                while(temp1 != temp2){
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                return temp1;
            }
        }
        return nullptr;
    }
};
