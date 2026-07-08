#include <iostream>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int x) {
        val = x;
        prev = next = child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* trav = head;
        stack<Node*> s;

        while (!(trav == NULL && s.empty())) {
            if (trav->child != NULL) {
                if (trav->next != NULL)
                    s.push(trav->next);

                trav->next = trav->child;
                trav->next->prev = trav;
                trav->child = NULL;
            }

            if (trav->next == NULL && !s.empty()) {
                trav->next = s.top();
                s.pop();
                trav->next->prev = trav;
            }

            trav = trav->next;
        }

        return head;
    }
};

int main() {
    // Creating a simple multilevel doubly linked list:
    // 1 - 2 - 3
    //     |
    //     4 - 5

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n2->child = n4;

    n4->next = n5;
    n5->prev = n4;

    Solution obj;
    Node* head = obj.flatten(n1);

    cout << "Flattened List: ";
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}

/*
Logic:
We traverse the doubly linked list using a pointer. Whenever we encounter a node having a child, we first save its next node (if it exists) onto a stack because
we need to return to it later. Then we connect the child list directly after the current node, update the previous pointer, and remove the child link by setting
it to NULL. Whenever we reach the end of the current list and the stack is not empty, we pop the stored node from the stack and attach it as the next node,
again updating its previous pointer. This process continues until both the current pointer becomes NULL and the stack is empty, producing a single-level
flattened doubly linked list in depth-first order.
*/
