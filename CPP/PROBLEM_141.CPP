# /*

LeetCode Problem: Linked List Cycle
Problem Number: 141

Approach:

* Use Floyd's Cycle Detection Algorithm
  (Tortoise and Hare).

* Initialize two pointers:

  * Slow Pointer (temp1)
    moves one step at a time.
  * Fast Pointer (temp2)
    moves two steps at a time.

* Traverse the linked list:

  * Move slow pointer by one node.
  * Move fast pointer by two nodes.

* If a cycle exists:

  * Both pointers will eventually
    meet at the same node.
  * Return true.

* If the fast pointer reaches NULL:

  * The linked list has no cycle.
  * Return false.

Why this approach?

* The fast pointer moves faster than
  the slow pointer.
* In a cyclic linked list, the fast
  pointer will eventually catch up to
  the slow pointer.

Example:
3 -> 2 -> 0 -> -4
^         |
|_________|

```
Output: true
```

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of nodes in the linked list

Key Concepts:

* Linked List
* Two Pointers
* Floyd's Cycle Detection Algorithm
* Fast and Slow Pointers

====================================================
*/


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(temp2!=NULL && temp2->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next->next;
            if(temp1==temp2){
                return true;
            }
        }
        return false;
    }
};
