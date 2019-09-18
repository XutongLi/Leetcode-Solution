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
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)   return res;
        string str = to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(str);
            return res;
        }
        if (root->left)
            addPath(root->left, str);
        if (root->right)
            addPath(root->right, str);
        return res;
    }
    void addPath(TreeNode* root, string str) {
        str += "->" + to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(str);
            return;
        }
        if (root->left)
            addPath(root->left, str);
        if (root->right)
            addPath(root->right, str);
    }
};