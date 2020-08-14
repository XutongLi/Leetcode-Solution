/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isBalanced(TreeNode *root, int &depth) {
        if (!root)  
            return true;
        int left = 0, right = 0;
        if (!isBalanced(root->left, left) || !isBalanced(root->right, right))
            return false;
        if (abs(left - right) > 1)
            return false;
        depth = max(left, right) + 1;
        return true;
    }
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, depth);
    }
};