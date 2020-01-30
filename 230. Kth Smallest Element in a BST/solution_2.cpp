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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *top;
        while (k > 0) {
            top = st.top();
            if (top->left) {
                st.push(top->left);
                top->left = nullptr;
            }
            else {
                st.pop();
                -- k;
                if (top->right)
                    st.push(top->right);
            }
        }
        return top->val;
    }
};
//DFS 中序遍历非递归写法