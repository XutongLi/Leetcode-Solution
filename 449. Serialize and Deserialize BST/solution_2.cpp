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
private:
    void preOrder(TreeNode *root, string &res) {
        if (!root) {
            res += "n-";
            return;
        }
        res += to_string(root->val) + "-";
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
    TreeNode *buildTree(const vector<string> &vec, int &idx) {
        if (vec[idx] == "n") {
            ++ idx;
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(vec[idx ++]));
        root->left = buildTree(vec, idx);
        root->right = buildTree(vec, idx);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        string res = "";
        preOrder(root, res);
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
        return buildTree(vec, idx);
    }
};
//preorder DFS
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));