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
    void flatten(TreeNode* root) {
        TreeNode *pre = nullptr;
        flatten(root, pre);
    }
    void flatten(TreeNode *node, TreeNode *&pre) {
        if (!node)  return;
        //node->left = pre;
        if (pre) {
            pre->right = node;
            pre->left = nullptr;
        }
        TreeNode *right = node->right;
        pre = node;
        flatten(node->left, pre);
        flatten(right, pre);
    }
};