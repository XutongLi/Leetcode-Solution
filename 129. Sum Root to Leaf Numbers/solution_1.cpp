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
    void dfs(TreeNode *root, int cur, int &sum) {
        cur = cur * 10 + root->val;
        if (!root->left && !root->right) {
            sum += cur;
            return;
        }
        if (root->left)
            dfs(root->left, cur, sum);
        if (root->right)
            dfs(root->right, cur, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0, cur = 0;
        if (root)
            dfs(root, cur, sum);
        return sum;
    }
};