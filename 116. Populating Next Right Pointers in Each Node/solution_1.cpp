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
        root->next = nullptr;
        connect(root, nullptr);
        return root;
    }
    void connect(Node* node, Node *r_father) {
        if (!node)
            return;
        if (node->left) {
            node->left->next = node->right;
            connect(node->left, node->right);
        }
        if (node->right) {
            if (r_father) {
                node->right->next = r_father->left;
                connect(node->right, r_father->left);
            }
            else {
                node->right->next = nullptr;
                connect(node->right, nullptr);
            }
        }
    }
};
//DFS