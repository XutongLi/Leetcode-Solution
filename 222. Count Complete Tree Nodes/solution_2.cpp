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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int lh = 0, rh = 0;
        TreeNode *l = root, *r = root;
        while (l) {
            l = l->left;
            ++ lh;
        }
        while (r) {
            r = r->right;
            ++ rh;
        }
        if (lh == rh)
            return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
//O(logn * logn)
//1 + 2 +... + h ~ O(h^2) h=logn