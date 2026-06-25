# /*

LeetCode Problem: Reverse Nodes in k-Group
Problem Number: 25

Approach:

* Use a dummy node to simplify handling
  changes at the head of the list.

* Process the linked list in groups
  of size k.

* For each group:

  * Find the kth node from the
    current position.
  * If fewer than k nodes remain,
    leave them unchanged.

* Reverse the nodes within the group:

  * Use three pointers:
    prev
    curr
    temp
  * Reverse links until reaching
    the next group's starting node.

* Reconnect:

  * Previous group → reversed group
  * Reversed group → next group

* Move to the next group and repeat.

Why this approach?

* Reversing links directly satisfies
  the problem requirement without
  modifying node values.
* Using a dummy node makes handling
  edge cases much easier.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5
k = 2

Output:
2 -> 1 -> 4 -> 3 -> 5

Input:
1 -> 2 -> 3 -> 4 -> 5
k = 3

Output:
3 -> 2 -> 1 -> 4 -> 5

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of nodes in the linked list

Key Concepts:

* Linked List
* Pointer Manipulation
* Group Reversal
* Dummy Node
* In-Place Reversal

====================================================
*/


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while(true) {

            ListNode* kth = prevGroup;
            for(int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }

            if(kth == NULL) {
                break;
            }

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            while(curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
        }

        return dummy.next;
    }
};
