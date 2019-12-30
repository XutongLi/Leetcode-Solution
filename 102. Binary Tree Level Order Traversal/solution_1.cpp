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
        queue<TreeNode*> q;
        q.push(root);
        int cur = 1, next = 0;
        vector<int> tmp;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            tmp.push_back(node->val);
            -- cur;
            if (node->left) {
                q.push(node->left);
                ++ next;
            }
            if (node->right) {
                q.push(node->right);
                ++ next;
            }
            if (cur == 0) {
                cur = next;
                next = 0;
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};