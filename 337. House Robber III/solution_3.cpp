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
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
    vector<int> helper(TreeNode *root) {
        if (!root)  return vector<int>(2, 0);
        auto left = helper(root->left);
        auto right = helper(root->right);
        vector<int> res(2);
        res[0] = root->val + left[1] + right[1];    //res[0]表示当前节点值加左右两子树不包含左右节点的最大值
        res[1] = max(left[0], left[1]) + max(right[0], right[1]);   //res[1]表示左右两子树最大值
        return res;
    }
};