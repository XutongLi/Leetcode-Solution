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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty()) {
            cnt ++;
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left == NULL && node->right == NULL)
                    return cnt;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return cnt;
    }
};