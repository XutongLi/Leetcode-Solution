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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        vector<int> in;
        inorder(root, in);
        for (int i = 1; i < in.size(); ++ i) 
            if (in[i] <= in[i - 1])
                return false;
        return true;
    }
    void inorder(TreeNode* root, vector<int> &in) {
        if (!root)
            return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
};