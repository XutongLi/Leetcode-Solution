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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return getString(root1) == getString(root2);
    }
    string getString(TreeNode* root) {
        if (root == NULL)   
            return "";
        if (root->left == NULL && root->right == NULL)
            return to_string(root->val) + "-";
        return getString(root->left) + getString(root->right);
    }
};