/*
====================================================
LeetCode Problem: Reverse Linked List
Problem Number: 206

Approach:
- Handle the edge case where the
  linked list is empty.

- Traverse the linked list and store
  all node values in a vector.

- Reverse the vector using the
  two-pointer technique:
    - One pointer starts from the
      beginning.
    - Another pointer starts from the
      end.
    - Swap elements until both
      pointers meet.

- Traverse the linked list again and
  overwrite each node's value with
  the reversed values from the vector.

- Return the head of the modified
  linked list.

Why this approach?
- Storing node values in a vector
  makes reversing straightforward.
- The linked list structure remains
  unchanged while the node values are
  updated to reflect the reversed
  order.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5

Vector:
[1, 2, 3, 4, 5]

After Reversal:
[5, 4, 3, 2, 1]

Output:
5 -> 4 -> 3 -> 2 -> 1

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
linked list by modifying the node
pointers directly, achieving O(n)
time and O(1) extra space. This
solution uses additional memory by
storing node values in a vector.

====================================================
*/




class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return nullptr;
        }
        ListNode* temp=head;
        vector<int> nums;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int left=0,right=nums.size()-1;
        while(left<right){
            int x=nums[left];
            nums[left]=nums[right];
            nums[right]=x;
            left++;
            right--;
        }
        temp=head;
        for(int i=0;i<nums.size();i++){
            temp->val=nums[i];
            temp=temp->next;
        }
        return head;
    }
};
