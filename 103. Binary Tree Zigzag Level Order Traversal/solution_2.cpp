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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool l2r = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> cur(n);
            for (int i = 0; i < n; ++ i) {
                TreeNode *tmp = q.front();
                q.pop();
                int idx = l2r ? i : n - i - 1;
                cur[idx] = tmp->val;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            l2r = !l2r;
            res.push_back(cur);
        }
        return res;
    }
};