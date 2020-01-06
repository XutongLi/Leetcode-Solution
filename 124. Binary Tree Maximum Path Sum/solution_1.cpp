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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        nodeMax(root, maxi);
        return maxi;
    }
    int nodeMax(TreeNode* node, int &maxi) {
        if (node == nullptr)
            return 0;
        int left = max(nodeMax(node->left, maxi), 0);
        int right = max(nodeMax(node->right, maxi), 0);
        maxi = max(maxi, node->val + left + right);
        return node->val + max(left, right);
    }
};