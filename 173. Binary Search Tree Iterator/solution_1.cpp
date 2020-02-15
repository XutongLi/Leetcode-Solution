/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        if (root)
            st.push(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *top = st.top();
        while (top->left) {
            st.push(top->left);
            top->left = nullptr;
            top = st.top();
        }
        st.pop();
        if (top->right)
            st.push(top->right);
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

//中序遍历非递归写法
//因为空间O(h)要求，所以必须使用此方法
//么个节点入栈一次，出栈一次，所以next平均时间复杂度为O(1)
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */