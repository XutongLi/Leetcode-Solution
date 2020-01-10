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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        unordered_map<TreeNode*, TreeNode*> son_pa;
        son_pa[root] = nullptr;
        st.push(root);
        //p q都找到时循环停止
        while (!(son_pa.find(p) != son_pa.end() && son_pa.find(q) != son_pa.end())) {
            TreeNode *node = st.top();
            st.pop();
            if (node->left) {
                st.push(node->left);
                son_pa[node->left] = node;
            }
            if (node->right) {
                st.push(node->right);
                son_pa[node->right] = node;
            }
        }
        unordered_set<TreeNode*> p_pa;  //存放p的所有祖先节点
        while (p) {
            p_pa.insert(p);
            p = son_pa[p];
        }
        while (p_pa.find(q) == p_pa.end()) {    //寻找最小公共祖先节点
            q = son_pa[q];
        }
        return q;
    }
};