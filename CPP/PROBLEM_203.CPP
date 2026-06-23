# /*

LeetCode Problem: Remove Linked List Elements
Problem Number: 203

Approach:

* First handle the special case where
  the head node itself contains the
  target value.

* Remove all matching nodes from the
  beginning of the list:

  * Move head forward.
  * Delete the removed node.

* Once the head is valid:

  * Use two pointers:
    temp1 -> current valid node
    temp2 -> next node

* Traverse the linked list:

  * If temp2 contains the target value:

    * Skip the node.
    * Delete it from memory.
    * Connect temp1 directly to the
      next node.
  * Otherwise:

    * Move both pointers forward.

* Continue until the end of the list
  is reached.

Why this approach?

* Removing head nodes requires special
  handling because changing the head
  affects the entire list.
* After fixing the head, the remaining
  nodes can be removed efficiently
  using pointer manipulation.

Example:
Input:
1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
val = 6

```
Output:
1 -> 2 -> 3 -> 4 -> 5
```

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of nodes in the linked list

Key Concepts:

* Linked List
* Pointer Manipulation
* In-Place Deletion

====================================================
*/



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return nullptr;
        }
        while(head != NULL && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        if(head == NULL){
            return nullptr;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        while(temp2 != NULL){
            if(temp2->val == val){
                temp1->next = temp2->next;
                delete temp2;
                temp2 = temp1->next;
            }else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return head;
    }
};
