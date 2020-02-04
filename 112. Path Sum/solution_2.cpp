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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right) {
            if (root->val == sum)
                return true;
            else
                return false;
        }
        return root->left && hasPathSum(root->left, sum - root->val) ||
            root->right && hasPathSum(root->right, sum - root->val);
    }
};