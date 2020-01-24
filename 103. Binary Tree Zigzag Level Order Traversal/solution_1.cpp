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
        vector<stack<TreeNode*>> st(2);
        int idx = 0;
        st[idx].push(root);
        vector<int> cur;
        while (!st[0].empty() || !st[1].empty()) {
            TreeNode *tmp = st[idx].top();
            st[idx].pop();
            cur.push_back(tmp->val);
            if (idx == 0) {
                if (tmp->left)
                    st[1 - idx].push(tmp->left);
                if (tmp->right)
                    st[1 - idx].push(tmp->right);
            }
            else {
                if (tmp->right)
                    st[1 - idx].push(tmp->right);
                if (tmp->left)
                    st[1 - idx].push(tmp->left);
            }
            if (st[idx].empty()) {
                res.push_back(cur);
                idx = 1 - idx;
                cur.clear();
            }
        }
        return res;
    }
};