/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return head;
        Node *ptr = head;
        while (ptr) {
            Node *node = new Node(ptr->val);
            node->next = ptr->next;
            ptr->next = node;
            ptr = ptr->next->next;
        }
        ptr = head;
        while (ptr) {
            ptr->next->random = ptr->random ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }
        ptr = head;
        Node *head2 = head->next, *ptr2 = head2;
        while (ptr2->next) {
            ptr->next = ptr->next->next;
            ptr = ptr->next;
            ptr2->next = ptr2->next->next;
            ptr2 = ptr2->next;
        }
        ptr->next = ptr->next->next;
        return head2;
    }
};