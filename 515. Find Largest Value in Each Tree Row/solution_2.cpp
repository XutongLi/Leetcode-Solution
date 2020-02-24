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
    void dfs(TreeNode *root, vector<int> &res, int depth) {
        if (!root)
            return;
        if (depth == res.size())
            res.push_back(root->val);
        else {
            res[depth] = max(res[depth], root->val);
        }
        dfs(root->left, res, depth + 1);
        dfs(root->right, res, depth + 1);
            
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};
//DFS