//Flatten a Multilevel Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void flat(Node* node, stack<Node*>& st) {
         if (node->child == nullptr) {
            if (node->next == nullptr) {
                st.push(node);
            } else {
              flat(node->next,st);
            }
        } else {
            Node* next = node->next;
            node->next = node->child;
			node->child->prev=node;
            flat(node->child,st);
            node->child = nullptr;
            if (next) {
                Node* n1 = st.top();
                n1->next=next;
                next->prev=n1;
                st.pop();
                flat(next,st);
            }
        }
    }

    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }
        stack<Node*> st;
        flat(head,st);

        return head;
    }
};
