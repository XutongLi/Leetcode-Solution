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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *tmp = st.top();
            st.pop();
            res.push_back(tmp->val);
            if (tmp->right)
                st.push(tmp->right);
            if (tmp->left)
                st.push(tmp->left);
        }
        return res;
    }
};