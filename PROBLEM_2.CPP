# /*

LeetCode Problem: Add Two Numbers
Problem Number: 2

Approach:

* Traverse both linked lists simultaneously.

* Initialize a carry variable:
  carry = 0

* For each node:

  * Extract values from both lists.
  * If a list reaches the end,
    use 0 as its value.

* Compute:
  sum = value1 + value2 + carry

* Store:
  digit = sum % 10
  carry = sum / 10

* Insert the digit into a new linked list.

* Continue until:

  * both lists are completely traversed
  * and carry becomes 0

Why this approach?

* Each node stores a single digit of
  the number in reverse order.
* Processing nodes one by one simulates
  normal addition exactly like adding
  numbers by hand.

Time Complexity: O(max(n,m))
Space Complexity: O(max(n,m))

Where:
n = nodes in first linked list
m = nodes in second linked list

====================================================
*/



#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:

    List(){
        head = tail = NULL;
    }

    Node* getHead(){
        return head;
    }

    void push_front(int val){

        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){

        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print(){

        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    List addToNumbers(List* l1, List* l2){

        Node* temp1 = l1->getHead();
        Node* temp2 = l2->getHead();

        List l3;

        int carry = 0;

        while(temp1 != NULL || temp2 != NULL || carry){

            int val1 = 0;
            int val2 = 0;

            if(temp1 != NULL){
                val1 = temp1->data;
            }

            if(temp2 != NULL){
                val2 = temp2->data;
            }

            int sum = val1 + val2 + carry;

            int digit = sum % 10;

            carry = sum / 10;

            l3.push_back(digit);

            if(temp1 != NULL){
                temp1 = temp1->next;
            }

            if(temp2 != NULL){
                temp2 = temp2->next;
            }
        }

        return l3;
    }
};

int main(){

    List l1;
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(3);

    List l2;
    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(4);

    List ans;

    ans = ans.addToNumbers(&l1, &l2);

    ans.print();

    return 0;
}
