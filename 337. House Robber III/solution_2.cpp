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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        return helper(root, mp);
    }
    int helper(TreeNode *root, unordered_map<TreeNode*, int> &mp) {
        if (!root)  return 0;
        if (mp.find(root) != mp.end())
            return mp[root];
        int val = 0;
        if (root->left)
            val += helper(root->left->left, mp) + helper(root->left->right, mp);
        if (root->right)
            val += helper(root->right->left, mp) + helper(root->right->right, mp);
        int res = max(val + root->val, helper(root->left, mp) + helper(root->right, mp));
        mp[root] = res;
        return res;
    }
};
//use map to store existed value (DP)