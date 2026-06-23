# /*

LeetCode Problem: Swap Nodes in Pairs
Problem Number: 24

Approach:

* Traverse the linked list in pairs.

* For every two adjacent nodes:

  * Swap their values using a
    temporary variable.

* Move two nodes ahead after each swap.

* Continue until:

  * The end of the list is reached, or
  * Only one node remains.

Why this approach?

* Instead of changing node connections,
  the solution swaps the values stored
  in adjacent nodes.
* This makes the implementation simple
  while achieving the required result.

Example:
Input:
1 -> 2 -> 3 -> 4

```
Output:
2 -> 1 -> 4 -> 3
```

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of nodes in the linked list

Key Concepts:

* Linked List Traversal
* Pairwise Processing
* Value Swapping

Note:
This solution swaps node values rather
than modifying node links. The official
follow-up asks for swapping actual nodes
without changing values.

====================================================
*/





class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL){
            return nullptr;
        }
        ListNode* first = head;
        ListNode* prev = head;
        while(prev != NULL && prev->next != NULL){
            int temp = prev->val;
            prev->val = prev->next->val;
            prev->next->val = temp;

            prev = prev->next->next;
        }
        return first;
    }
};
