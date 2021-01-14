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
    void dfs(TreeNode *root, string cur, vector<string> &res) {
        cur += ("->" + to_string(root->val));
        if (!root->left && !root->right) {
            res.push_back(cur.substr(2));
            return;
        }
        if (root->left) dfs(root->left, cur, res);
        if (root->right)    dfs(root->right, cur, res);
}
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root)  return res;
        dfs(root, "", res);
        return res; 
    }
};
