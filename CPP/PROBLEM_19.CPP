/*
====================================================
LeetCode Problem: Remove Nth Node From End of List
Problem Number: 19

Approach:
- Traverse the linked list once to
  determine its total length.

- If the list is empty, return
  nullptr.

- If the node to be removed is the
  head node (n == size):
    - Update the head pointer.
    - Delete the old head.
    - Return the new head.

- Otherwise:
    - Calculate the index of the node
      preceding the target node:
          index = size - n - 1

    - Traverse to that node.

    - Adjust the pointers to bypass
      the target node.

    - Delete the removed node.

- Return the updated head.

Why this approach?
- Knowing the total length makes it
  easy to determine the position of
  the node to remove from the
  beginning of the list.
- Pointer manipulation removes the
  target node without affecting the
  remaining list.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5
n = 2

Output:
1 -> 2 -> 3 -> 5

Input:
1
n = 1

Output:
Empty List

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of nodes in the linked list

Key Concepts:
- Linked List
- Two Pass Traversal
- Pointer Manipulation
- Node Deletion

====================================================
*/



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        if (size == 0)
            return nullptr;
        // Handle deletion of the first node
        if (n == size) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* prev = head;
        temp = head->next;
        int x = size - n - 1;
        while (x > 0) {
            prev = prev->next;
            temp = temp->next;
            x--;
        }
        prev->next = temp->next;
        delete temp;
        return head;
    }
};
