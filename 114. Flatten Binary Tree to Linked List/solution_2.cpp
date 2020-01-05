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
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left && root->right) {
                TreeNode *l = root->left;
                while (l->right)
                    l = l->right;
                l->right = root->right;
            }
            if (root->left) {
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
//非递归