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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
    bool isValidBST(TreeNode *root, TreeNode *mini, TreeNode *maxi) {
        if (!root)
            return true;
        if (mini && mini->val >= root->val || maxi && maxi->val <= root->val)
            return false;
        return isValidBST(root->left, mini, root) && isValidBST(root->right, root, maxi);
    }
};