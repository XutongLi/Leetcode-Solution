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
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> cur;
            int len = q.size();
            while (len --) {
                auto front = q.front();
                q.pop();
                cur.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            res.push_back(cur);
        }
        return res;
    }
};