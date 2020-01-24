/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        Node *firstofline = root, *cur = nullptr;
        while (firstofline->left) {
            cur = firstofline;
            while (cur) {
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : nullptr;
                cur = cur->next;
            }
            firstofline = firstofline->left;
        }
        return root;
    }
};
//BFS