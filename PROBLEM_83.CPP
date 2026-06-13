# /*

LeetCode Problem: Remove Duplicates from Sorted List
Problem Number: 83

Approach:

* Since the linked list is already sorted,
  duplicate values appear consecutively.

* Use two pointers:

  * temp1 points to the current node.
  * temp2 points to the next node.

* Traverse the list:

  * If both nodes contain the same value:

    * Remove the duplicate node.
    * Connect temp1 directly to the
      next unique node.
    * Delete the duplicate node to
      free memory.

  * Otherwise:

    * Move both pointers forward.

* Continue until the end of the list
  is reached.

Why this approach?

* Sorting guarantees that duplicates
  are adjacent, allowing them to be
  removed in a single traversal.

Time Complexity: O(n)
Space Complexity: O(1)

Where:
n = number of nodes in the linked list

Key Concepts:

* Linked List Traversal
* In-Place Modification
* Duplicate Removal

====================================================
*/



    /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode() : val(0), next(nullptr) {}
    *     ListNode(int x) : val(x), next(nullptr) {}
    *     ListNode(int x, ListNode *next) : val(x), next(next) {}
    * };
    */
    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if(head == NULL){
                return 0;
            }
            ListNode* temp1=head;
            ListNode* temp2=head->next;
            while(temp2!=NULL){
                if(temp1->val==temp2->val){
                    temp1->next=temp2->next;
                    delete temp2;
                    temp2=temp1->next;
                }else{
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
            }
            return head;
        }
    };
