class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto e : flights)
            g[e[0]].push_back({e[1], e[2]});
        queue<pair<int, int>> q;
        q.push({src, 0});
        int res = INT_MAX;
        for (int i = 0; i <= K; ++ i) {
            int n = q.size();
            while (n --) {
                auto p = q.front();
                int from = p.first, cum = p.second;
                q.pop();
                for (auto pair : g[from]) {
                    if (cum + pair.second > res)
                        continue;
                    if (pair.first == dst) {
                        res = min(res, cum + pair.second);
                    } 
                    else
                        q.push({pair.first, cum + pair.second});
                }
            }  
        }
        return res == INT_MAX ? -1 : res;
    }
};

// BFS
// 此题中效率最高
