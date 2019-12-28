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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            if (cur->left) {
                st.push(cur->left);
                cur->left = nullptr;
            }
            else {
                res.push_back(cur->val);
                st.pop();
                if (cur->right)
                    st.push(cur->right);
            }
        }
        return res;
    }
};