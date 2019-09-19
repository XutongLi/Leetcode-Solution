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
    int max_diff = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)   return 0;
        findMax(root);
        return max_diff;
    }
    int findMax(TreeNode* root) {
        if (root == NULL)   return 0;
        int left = findMax(root->left);
        int right = findMax(root->right);
        max_diff = max(left + right, max_diff);
        return max(left, right) + 1;
    }
};