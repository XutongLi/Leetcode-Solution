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
    vector<vector<int>> res;
    // vector<vector<int>>::iterator iter = res.begin();
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int size = q.size();
            while (size -- > 0) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.insert(res.begin(), tmp);
        }
        return res;
    }
};