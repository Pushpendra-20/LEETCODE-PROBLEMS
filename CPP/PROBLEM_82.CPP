# /*

LeetCode Problem: Remove Duplicates from Sorted List II
Problem Number: 82

Approach:

* Use a dummy node before the head
  to simplify handling deletions at
  the beginning of the list.

* Maintain two pointers:

  * prev: points to the last confirmed
    unique node.
  * curr: traverses the linked list.

* For each node:

  * Check if it has duplicate values
    following it.

* If duplicates are found:

  * Move curr until the last node
    of that duplicate group.
  * Skip the entire group by linking
    prev->next to curr->next.

* If no duplicates are found:

  * Move prev forward.

* Continue until the end of the list.

* Return dummy.next as the new head.

Why this approach?

* The problem requires removing all
  nodes that have duplicate values,
  not just the extra copies.
* The dummy node helps handle cases
  where duplicates appear at the
  beginning of the list.

Example:

Input:
1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5

Output:
1 -> 2 -> 5

Input:
1 -> 1 -> 1 -> 2 -> 3

Output:
2 -> 3

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of nodes in the linked list

Key Concepts:

* Linked List
* Dummy Node
* Two Pointers
* Duplicate Removal
* Pointer Manipulation

====================================================
*/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return nullptr;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while(curr != NULL){
            if(curr->next != NULL && curr->val == curr->next->val){
                while(curr->next != NULL &&
                      curr->val == curr->next->val){
                    curr = curr->next;
                }
                prev->next = curr->next;
            }
            else{
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};
