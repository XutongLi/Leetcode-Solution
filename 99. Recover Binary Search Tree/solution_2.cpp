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
    void inorder(TreeNode *root, TreeNode *&pre, TreeNode *&big, TreeNode *&small) {
        if (!root)	return;
        inorder(root->left, pre, big, small);
        if (pre && root->val < pre->val) {
            small = root;
            if (!big)		big = pre;
        }
        pre = root;
        inorder(root->right, pre, big, small);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre = nullptr, *big = nullptr, *small = nullptr;
        inorder(root, pre, big, small);
        swap(big->val, small->val);
    }
};

//inorder traversal dfs
//time O(n)  space O(1)