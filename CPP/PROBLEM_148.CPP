# /*

LeetCode Problem: Sort List
Problem Number: 148

Approach:

* Handle the edge case where the
  linked list is empty.

* Traverse the linked list and store
  all node values in a vector.

* Sort the vector in ascending order
  using the built-in sort() function.

* Traverse the linked list again and
  replace each node's value with the
  corresponding sorted value from the
  vector.

* Return the head of the sorted list.

Why this approach?

* Extracting node values into an array
  allows efficient sorting using the
  standard library.
* Updating the original linked list
  with sorted values produces the
  required sorted order without
  changing the node structure.

Example:

Input:
4 -> 2 -> 1 -> 3

Vector:
[4, 2, 1, 3]

Sorted Vector:
[1, 2, 3, 4]

Output:
1 -> 2 -> 3 -> 4

Time Complexity: O(n log n)
Space Complexity: O(n)

Where:
n = number of nodes in the linked list

Key Concepts:

* Linked List
* Sorting
* Vector
* Traversal

Note:
The optimal solution uses Merge Sort
on the linked list itself, achieving
O(n log n) time and O(1) extra space
(excluding recursion stack).

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
