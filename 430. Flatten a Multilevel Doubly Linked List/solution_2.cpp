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
    Node* flatten(Node* head) {
        if (!head)  return nullptr;
        for (Node *cur = head; cur; cur = cur->next) {
            if (cur->child) {
                auto next = cur->next;
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
                auto p = cur->next;
                while (p->next) 
                    p = p->next;
                p->next = next;
                if (next)
                    next->prev = p;
            }
        }
        return head;
    }
};
//non recursize solution