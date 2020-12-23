class Solution {
private:
    const int INF= 1e9;
    void dfs(vector<vector<pair<int, int>>> &graph, int src, int dst, int K, int &res, int cur) {
        if (K < 0)
            return;
        for (auto p : graph[src]) {
            int to = p.first, price = p.second;
            if (cur + price > res)
                continue;
            if (to == dst)
                res = min(res, cur + price);
            dfs(graph, to, dst, K - 1, res, cur + price);
        }
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto vec : flights)
            graph[vec[0]].push_back({vec[1], vec[2]});
        int res = INF;
        dfs(graph, src, dst, K, res, 0);
        return res == INF ? -1 : res;
    }
};
// DFS
