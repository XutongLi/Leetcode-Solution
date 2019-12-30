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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *build(const vector<int> &preorder, int pl, int pr, const vector<int> &inorder, int il, int ir) {
        if (pl > pr || il > ir)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pl]);
        int ln = il;
        while (inorder[ln] != preorder[pl])
            ++ ln;
        root->left = build(preorder, pl + 1, pl + 1 + ln - il - 1, inorder, il, ln - 1);
        root->right = build(preorder, pl + 1 + ln - il, pr, inorder, ln + 1, ir);
        return root;
    }
};
//先序第一个为根节点，再在中序中找到根节点位置，确定左右分支的节点