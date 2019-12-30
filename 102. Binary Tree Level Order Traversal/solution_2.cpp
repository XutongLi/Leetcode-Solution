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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        dfs(root, 0, res);
        return res;
    }
    void dfs(TreeNode *node, int depth, vector<vector<int>> &res) {
        if (res.size() == depth)
            res.push_back({});
        res[depth].push_back(node->val);
        if (node->left)
            dfs(node->left, depth + 1, res);
        if (node->right)
            dfs(node->right, depth + 1, res);
    }
};