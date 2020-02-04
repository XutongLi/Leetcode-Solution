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
    TreeNode *build(const vector<int> &in, int inStart, int inEnd, const vector<int> &post, int postStart, int postEnd) {
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(post[postEnd]);
        int root_in_idx = inStart;
        for (; in[root_in_idx] != post[postEnd]; ++ root_in_idx);
        int left_len = root_in_idx - inStart;
        root->left = build(in, inStart, root_in_idx - 1, post, postStart, postStart + left_len - 1);
        root->right = build(in, root_in_idx + 1, inEnd, post, postStart + left_len, postEnd - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
            return nullptr;
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
//O(n^2)