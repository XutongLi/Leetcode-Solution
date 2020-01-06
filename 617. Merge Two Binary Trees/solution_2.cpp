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
        if (!t1 && !t2)
            return nullptr;
        int val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
        TreeNode *node = new TreeNode(val);
        node->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
        node->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        return node;
    }
};