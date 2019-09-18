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
        if (root == NULL)
            return false;
        return helper(root, sum);
    }
    bool helper(TreeNode* root, int sum) {
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum)
                return true;
            else 
                return false;
        }
        if (root->left == NULL)
            return helper(root->right, sum - root->val);
        if (root->right == NULL)
            return helper(root->left, sum - root->val);
        return helper(root->right, sum - root->val) || helper(root->left, sum - root->val);
    }
};