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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *tmp = st.top();
            if (!tmp->left && !tmp->right) {
                res.push_back(tmp->val);
                st.pop();
            }
            else {
                if (tmp->right) {
                    st.push(tmp->right);
                    tmp->right = nullptr;
                }
                if (tmp->left) {
                    st.push(tmp->left);
                    tmp->left = nullptr;
                }
            } 
        }
        return res;
    }
};