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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *node;
        if (t1 && t2) {
            node = new TreeNode(t1->val + t2->val);
            node->left = mergeTrees(t1->left, t2->left);
            node->right = mergeTrees(t1->right, t2->right);
        }
        else if (t1) {
            node = new TreeNode(t1->val);
            node->left = mergeTrees(t1->left, nullptr);
            node->right = mergeTrees(t1->right, nullptr);
        }
        else if (t2) {
            node = new TreeNode(t2->val);
            node->left = mergeTrees(nullptr, t2->left);
            node->right = mergeTrees(nullptr, t2->right);
        }
        else
            node = nullptr;
        
        return node;
    }
};