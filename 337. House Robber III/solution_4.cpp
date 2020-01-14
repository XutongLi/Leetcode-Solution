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
    int rob(TreeNode* root) {
        int l, r;
        return helper(root, l, r);
    }
    int helper(TreeNode *node, int &l, int &r) {
        if (!node)  return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = helper(node->left, ll, lr);     //subtree max 
        r = helper(node->right, rl, rr);
        return max(node->val + ll + lr + rl + rr, l + r);
    }
};