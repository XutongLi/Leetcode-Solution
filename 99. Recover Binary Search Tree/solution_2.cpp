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
    void inorder(TreeNode *root, TreeNode *&pre, TreeNode *&small, TreeNode *&big) {
        if (!root)
            return;
        inorder(root->left, pre, small, big);
        if (pre && !big) {      //big取第一个当前节点大于小于上一个节点的情况（取上一个）
            if (root->val < pre->val) 
                big = pre;
        }
        if (pre) {      //small取最后一个当前节点小于上一个节点的情况（取当前）
            if (root->val < pre->val) 
                small = root;
        }
        pre = root;
        inorder(root->right, pre, small, big);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre = nullptr, *small = nullptr, *big = nullptr;  //small为两个交换的数字中正确情况下应该靠前的，big为应该靠后的
        inorder(root, pre, small, big);
        int val = small->val;
        small->val = big->val;
        big->val = val;
    }
};
//inorder traversal dfs
//time O(n)  space O(1)