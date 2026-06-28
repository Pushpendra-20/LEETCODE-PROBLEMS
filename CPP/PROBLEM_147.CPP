/*
====================================================
LeetCode Problem: Insertion Sort List
Problem Number: 147

Approach:
- Handle the edge case where the
  linked list is empty.

- Traverse the linked list and store
  all node values in a vector.

- Sort the vector in ascending order
  using the built-in sort() function.

- Traverse the linked list again and
  overwrite each node's value with
  the corresponding sorted value.

- Return the head of the sorted list.

Why this approach?
- Instead of performing insertion
  sort directly on the linked list,
  the solution extracts all values,
  sorts them using the STL sort()
  function, and writes them back into
  the original list.

- This produces the correct sorted
  linked list with a simple and
  efficient implementation.

Example:

Input:
4 -> 2 -> 1 -> 3

Extracted Values:
[4, 2, 1, 3]

Sorted Values:
[1, 2, 3, 4]

Output:
1 -> 2 -> 3 -> 4

Time Complexity: O(n log n)
Space Complexity: O(n)

Where:
n = number of nodes in the linked list

Key Concepts:
- Linked List
- Sorting
- Vector
- STL sort()

Note:
The expected solution performs
Insertion Sort directly on the
linked list with O(n²) time and
O(1) extra space. This solution
uses STL sorting instead, resulting
in O(n log n) time and O(n) extra
space.

====================================================
*/


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL){
            return nullptr;
        }
        vector<int> nums;
        int i=0;
        ListNode* temp=head;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
            i++;
        }
        sort(nums.begin(),nums.end());
        temp=head;
        i=0;
        while(temp!=NULL){
            temp->val=nums[i];
            temp=temp->next;
            i++;
        }
        return head;
    }
};
