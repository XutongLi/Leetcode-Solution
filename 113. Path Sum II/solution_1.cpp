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
private:
    void helper(TreeNode *root, int sum, vector<int> &cur, vector<vector<int>> &res) {
        cur.push_back(root->val);
        if (!root->left && !root->right && sum == root->val)
            res.push_back(cur);
        if (root->left) 
            helper(root->left, sum - root->val, cur, res);
        if (root->right) 
            helper(root->right, sum - root->val, cur, res);
        cur.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> cur;
        helper(root, sum, cur, res);
        return res;
    }
};