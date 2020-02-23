class Solution {    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 0)
            return vector<int>();
        if (n == 1)
            return vector<int>{0};
        vector<unordered_set<int>> graph(n);
        for (auto edge : edges) {   //构建图
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        vector<int> cur;
        for (int v = 0; v < n; ++ v) {
            if (graph[v].size() == 1)
                cur.push_back(v);
        }
        while (true) {
            vector<int> next;
            for (auto v : cur) {
                for (auto nei : graph[v]) {
                    graph[nei].erase(v);
                    if (graph[nei].size() == 1)
                        next.push_back(nei);
                }
            }
            if (next.empty())
                return cur;
            cur = next;
        }
        return cur;
    }
};
//BFS time O(n)
//iteratively deleting leaves
//第一层为所有叶子节点，逐层获取节点，直到最后一层