/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        int n = 0;
        unordered_set<int> st;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            n = max(n, top->val);
            st.insert(top->val);
            for (auto nei : top->neighbors) {
                if (st.find(nei->val) == st.end())
                    q.push(nei);
            }
        }
        vector<Node*> ptrs(n);
        for (int i = 0; i < n; ++ i)
            ptrs[i] = new Node(i + 1);
        vector<bool> visited(n + 1, false);
        q.push(node);
        visited[node->val] = true;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            for (auto nei : top->neighbors) {
                ptrs[top->val - 1]->neighbors.push_back(ptrs[nei->val - 1]);
                if (!visited[nei->val]) {
                    q.push(nei);
                    visited[nei->val] = true;
                }
            }
        }
        return ptrs[node->val - 1];
    }
};
//BFS