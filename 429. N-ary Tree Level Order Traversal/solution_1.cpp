/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            while (n -- > 0) {
                Node *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                for (auto c : node->children) 
                    q.push(c);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
///BFS