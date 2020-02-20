/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key) {
            if (!root->right) {
                TreeNode *left = root->left;
                delete root;
                root = nullptr;
                return left;
            }
            else {
                TreeNode *ptr = root->right;
                while (ptr->left)
                    ptr = ptr->left;
                swap(root->val, ptr->val);
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};
//solve all binary tree delete problem (not only BST)
//time O(n) n is the num of tree node