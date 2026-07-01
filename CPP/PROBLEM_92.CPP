/*
====================================================
LeetCode Problem: Reverse Linked List II
Problem Number: 92

Approach:
- Handle the edge case where the
  linked list is empty.

- Traverse the linked list and store
  all node values in a vector.

- Convert the given positions to
  zero-based indexing:
      left = left - 1
      right = right - 1

- Reverse the elements between
  the indices left and right using
  the two-pointer technique.

- Traverse the linked list again
  and overwrite each node's value
  with the updated values from
  the vector.

- Return the modified linked list.

Why this approach?
- Storing node values in a vector
  allows easy random access.
- Reversing only the required
  portion of the vector simplifies
  the implementation.
- Writing the values back updates
  the linked list without changing
  the node connections.

Example:

Input:
head = 1 -> 2 -> 3 -> 4 -> 5
left = 2
right = 4

Vector:
[1, 2, 3, 4, 5]

After Reversal:
[1, 4, 3, 2, 5]

Output:
1 -> 4 -> 3 -> 2 -> 5

Time Complexity: O(n)
Space Complexity: O(n)

Where:
n = number of nodes in the linked list

Key Concepts:
- Linked List
- Vector
- Two Pointers
- Array Reversal

Note:
The optimal solution reverses the
linked list in-place by modifying
node pointers, achieving O(n) time
and O(1) extra space. This solution
uses additional memory to simplify
the implementation.

====================================================
*/



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL){
            return nullptr;
        }
        ListNode* temp = head;
        vector<int> nums;
        while(temp != NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int i = left - 1;
        int j = right - 1;
        int x;
        while(i < j){
            x = nums[i];
            nums[i] = nums[j];
            nums[j] = x;
            i++;
            j--;
        }
        temp = head;
        int y = 0;
        while(temp != NULL){
            temp->val = nums[y];
            temp = temp->next;
            y++;
        }
        return head;
    }
};
