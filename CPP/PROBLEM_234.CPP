/*
====================================================
LeetCode Problem: Palindrome Linked List
Problem Number: 234

Approach:
- Handle the edge case where the
  linked list is empty.

- Traverse the linked list and store
  all node values in a vector.

- Initialize two pointers:
    - left at the beginning.
    - right at the end.

- Compare elements from both ends:
    - If the values differ,
      return false.
    - Otherwise, move both pointers
      toward the center.

- If all corresponding values match,
  return true.

Why this approach?
- Storing node values in a vector
  allows direct access from both
  ends of the list.
- The two-pointer technique provides
  an easy way to verify whether the
  sequence of values forms a
  palindrome.

Example:

Input:
1 -> 2 -> 2 -> 1

Vector:
[1, 2, 2, 1]

Comparison:
1 == 1 ✓
2 == 2 ✓

Output:
true

Input:
1 -> 2

Output:
false

Time Complexity: O(n)
Space Complexity: O(n)

Where:
n = number of nodes in the linked list

Key Concepts:
- Linked List
- Vector
- Two Pointers
- Palindrome Checking

Note:
The optimal solution reverses the
second half of the linked list and
compares both halves, achieving
O(n) time and O(1) extra space.

====================================================
*/





class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return false;
        }
        ListNode* temp=head;
        vector<int> nums;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int n=nums.size();
        int left=0,right=n-1;
        for(int i=0;i<n/2;i++){
            if(nums[left]!=nums[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
