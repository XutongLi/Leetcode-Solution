/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode *root, TreeNode *&pre) {
        if (!root)  return;
        TreeNode *left = root->left, *right = root->right;
        if (pre) {
            pre->right = root;
            pre->left = nullptr;
        }
        pre = root;
        inorder(left, pre);
        inorder(right, pre);
    }
public:
    void flatten(TreeNode* root) {
        TreeNode *pre = nullptr;
        inorder(root, pre);
    }
};