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
        Node *node = root->next;
        while (node) {
            if (node->left) {
                node = node->left;
                break;
            }
            else if (node->right) {
                node = node->right;
                break;
            }
            node = node->next;
        }
        if (root->left)
            root->left->next = root->right ? root->right : node;
        if (root->right)
            root->right->next = node;
        connect(root->right);
        connect(root->left);    //左右子节点的connect不能颠倒，先构建右节点
        return root;
    }
};
//dfs