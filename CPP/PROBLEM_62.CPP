# /*

LeetCode Problem: Rotate List
Problem Number: 61

Approach:

* Handle edge cases:

  * Empty list
  * Single-node list
  * k = 0

* Find the length of the linked list
  and store the last node.

* Since rotating by the list length
  results in the same list:
  k = k % length

* If k becomes 0:

  * Return the original list.

* Connect the last node to the head
  to form a circular linked list.

* Find the new tail node:
  steps = length - k

* Move to the node just before the
  new head.

* Break the circular link:

  * newHead = newTail->next
  * newTail->next = NULL

* Return the new head.

Why this approach?

* Forming a circular linked list
  allows rotation without repeatedly
  moving nodes.
* Only one traversal is needed after
  computing the length.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5
k = 2

Output:
4 -> 5 -> 1 -> 2 -> 3

Explanation:
Rotating right by 2 positions moves
the last two nodes to the front.

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of nodes in the linked list

Key Concepts:

* Linked List
* Circular Linked List
* Pointer Manipulation
* Modulo Optimization

====================================================
*/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        int length = 1;
        ListNode* temp1 = head;
        while(temp1->next != NULL){
            length++;
            temp1 = temp1->next;
        }
        k = k % length;
        if(k == 0){
            return head;
        }
        temp1->next = head;  // make circular
        int steps = length - k;
        ListNode* temp2 = head;
        while(steps > 1){
            temp2 = temp2->next;
            steps--;
        }
        ListNode* newHead = temp2->next;
        temp2->next = NULL;
        return newHead;
    }
};
