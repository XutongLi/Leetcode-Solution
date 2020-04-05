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
    void dfs(TreeNode *root, int depth, int &left, int &maxDepth) {
        if (!root->left && !root->right) {
            if (depth > maxDepth) {
                left = root->val;
                maxDepth = depth;
            }
            return;
        }
        if (root->left)
            dfs(root->left, depth + 1, left, maxDepth);
        if (root->right)
            dfs(root->right, depth + 1, left, maxDepth);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int left = 0, maxDepth = 0;
        dfs(root, 1, left, maxDepth);
        return left;
    }
};
//DFS