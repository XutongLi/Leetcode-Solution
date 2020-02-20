/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (!top) {
                res += "n-";
                continue;
            }
            res += to_string(top->val) + "-";
            q.push(top->left);
            q.push(top->right);
        }
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        stringstream str(data);
        string tmp;
        vector<string> vec;
        while (getline(str, tmp, '-')) 
            vec.push_back(tmp);
        int idx = 0;
        TreeNode *root = new TreeNode(stoi(vec[idx ++]));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            top->left = vec[idx] == "n" ? nullptr : new TreeNode(stoi(vec[idx]));
            ++ idx;
            top->right = vec[idx] == "n" ? nullptr : new TreeNode(stoi(vec[idx]));
            ++ idx;
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
        return root;
    }
};
//层序遍历
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));