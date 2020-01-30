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
    void inorder(TreeNode *root, int &cnt, int k, int &res) {
        if (!root)  return;
        inorder(root->left, cnt, k, res);
        if (++ cnt == k) {
            res = root->val;
            return;
        }
        inorder(root->right, cnt, k, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, res;
        inorder(root, cnt, k, res);
        return res;
    }
};
//DFS