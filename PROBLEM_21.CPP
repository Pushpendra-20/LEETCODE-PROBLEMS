# /*

LeetCode Problem: Merge Two Sorted Lists
Problem Number: 21

Approach:

* Use recursion to merge both linked lists.

* Base cases:

  * If the first list is empty,
    return the second list.
  * If the second list is empty,
    return the first list.

* Compare the current nodes of both lists:

  * If first node value is smaller
    or equal:
    connect first node with the
    result of recursive call on
    remaining nodes.

  * Otherwise:
    connect second node with the
    result of recursive call.

* Continue until all nodes are merged.

Why this approach?

* Since both linked lists are already
  sorted, comparing current nodes and
  recursively attaching smaller nodes
  maintains sorted order.

Time Complexity: O(n + m)
Space Complexity: O(n + m)

Where:
n = number of nodes in first list
m = number of nodes in second list

(Note: Recursive stack space contributes
to space complexity.)

====================================================
*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }
        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next,head2);
            return head1;
        }else{
            head2->next = mergeTwoLists(head1,head2->next);
            return head2;
        }
    }
};
