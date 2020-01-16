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
            return "[]";
        string str = "["; 
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *tmp = q.front(); 
            if (!tmp) {
                str += "null,";
                q.pop();
                continue;
            }
            str += to_string(tmp->val) + ",";
            q.pop();
            q.push(tmp->left);
            q.push(tmp->right);
        }
        return str + "]";
    }//[1,2,3,null,null,4,5,null,null]

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1, data.size() - 2);
        vector<string> vec;
        split(data, vec);
        TreeNode *root = (data[1] == 'n' || data[1] == ']') ? nullptr : new TreeNode(stoi(vec[0]));
        if (!root)  return root;
        queue<TreeNode*> q;
        q.push(root);
        int idx = 1;
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            tmp->left = vec[idx] == "null" ? nullptr : new TreeNode(stoi(vec[idx]));
            ++ idx;
            if (tmp->left)
                q.push(tmp->left);
            tmp->right = vec[idx] == "null" ? nullptr : new TreeNode(stoi(vec[idx]));
            ++ idx;
            if (tmp->right)
                q.push(tmp->right);
            q.pop();
        }
        return root;
    }
    void split(const string &str, vector<string> &vec) {
        int k = 0;
        for (int i = 1; i < str.size(); ++ i) {
            if (str[i] == ',') {
                vec.push_back(str.substr(k, i - k));
                k = i + 1;
            }
        }
        vec.push_back(str.substr(k, static_cast<int>(str.size()) - k));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));