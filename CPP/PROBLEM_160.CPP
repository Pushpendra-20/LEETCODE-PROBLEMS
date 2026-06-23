# /*

LeetCode Problem: Intersection of Two Linked Lists
Problem Number: 160

Approach:

* Calculate the lengths of both linked
  lists separately.

* Determine the difference in lengths.

* Move the pointer of the longer list
  forward until both lists have the
  same number of remaining nodes.

* Traverse both lists simultaneously:

  * Compare node addresses, not values.
  * If both pointers point to the
    same node, an intersection is found.

* Return the intersection node.

* If no intersection exists,
  return nullptr.

Why this approach?

* Aligning both lists ensures that
  corresponding nodes are checked
  from equal distances to the end.
* Comparing node addresses correctly
  identifies the shared node.

Example:

List A:
4 -> 1

8 -> 4 -> 5
/
List B:
5 -> 6 -> 1

Output:
Node with value 8

Time Complexity: O(n + m)
Space Complexity: O(1)

Where:
n = number of nodes in List A
m = number of nodes in List B

Key Concepts:

* Linked List
* Length Difference
* Pointer Alignment
* Intersection Detection

====================================================
*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        int lenA=0,lenB=0;
        if(headA == NULL || headB == NULL){
            return nullptr;
        }
        while(temp1!=NULL){
            lenA++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            lenB++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
        if(lenA > lenB){
            while(lenA!=lenB){
                temp1=temp1->next;
                lenA--;
            }
        }else{
            while(lenB!=lenA){
                temp2=temp2->next;
                lenB--;
            }
        }
        while(temp1 != NULL && temp2 != NULL){
            if(temp1==temp2){
                return temp1;
            }else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return nullptr;
    }
};
