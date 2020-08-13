/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isSym(vector<int> &line) {
        vector<int> tmp(line.rbegin(), line.rend());
        for (int i = 0; i < line.size(); ++ i) {
            if (line[i] != tmp[i])
                return false;
        }
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> line;
            int len = q.size();
            while (len --) {
                auto front = q.front();
                q.pop();
                if (front == nullptr)
                    line.push_back(-1);
                else {
                    line.push_back(front->val);
                    q.push(front->left);
                    q.push(front->right);
                }
            }
            if (!isSym(line))
                return false;
        }
        return true;
    }
};