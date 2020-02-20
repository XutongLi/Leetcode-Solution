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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else {
            TreeNode *new_root = nullptr;
            if (root->left && root->right) {
                new_root = root->left;
                while (new_root->right)
                    new_root = new_root->right;
                new_root->right = root->right;
                new_root = root->left;
            }
            else if (root->left) 
                new_root = root->left;
            else
                new_root = root->right;
            delete root;
            root = nullptr;
            return new_root;
        }
        return root;
    }
};
//solve BST problem O(h)
//            10
//      5              15
//   3     7  
// 1  4  6  8
// key = 5
//            10
//   3                 15
// 1   4
//        7
//       6  8