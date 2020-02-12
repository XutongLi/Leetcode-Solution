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
    void dfs(TreeNode *root, vector<TreeNode*> &vec) {
        if (!root)
            return;
        dfs(root->left, vec);
        vec.push_back(root);
        dfs(root->right, vec);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vec;
        dfs(root, vec);
        TreeNode *big = nullptr, *small = nullptr;
        int n = vec.size();
        for (int i = 0; i < n; ++ i) {
            if (i > 0 && vec[i]->val < vec[i - 1]->val)
                small = vec[i];
            if (!big && i < n - 1 && vec[i]->val > vec[i + 1]->val)
                big = vec[i];
        }
        int val = big->val;
        big->val = small->val;
        small->val = val;
    }
};
//dfs
//time O(n)  space O(n)