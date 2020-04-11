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
    void dfs(TreeNode *node, int depth, int v, int d) {
        if (!node)  return;
        if (depth + 1 == d) {
            auto tmp = node->left;
            node->left = new TreeNode(v);
            node->left->left = tmp;
            tmp = node->right;
            node->right = new TreeNode(v);
            node->right->right = tmp;
            return;
        }
        dfs(node->left, depth + 1, v, d);
        dfs(node->right, depth + 1, v, d);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *node = new TreeNode(v);
            node->left = root;
            return node;
        }
        dfs(root, 1, v, d);
        return root;
    }
};
//dfs