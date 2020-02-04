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
    unordered_map<int, int> mp;
    int postIdx;
    TreeNode *build(const vector<int> &post, int l, int r) {
        if (l > r)  
            return nullptr;
        TreeNode *root = new TreeNode(post[postIdx --]);
        if (l == r)
            return root;
        int idx = mp[root->val];
        root->right = build(post, idx + 1, r);      //先构建右子树（与取post有关）
        root->left = build(post, l, idx - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++ i)
            mp[inorder[i]] = i;
        postIdx = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
    }
};
//O(n)