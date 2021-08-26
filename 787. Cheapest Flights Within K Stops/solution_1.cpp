class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto f : flights) {
            g[f[0]].push_back({f[1], f[2]});
        }
        int mini = INT_MAX;
        queue<pair<int, int>> q;
        vector<int> minCost(n, INT_MAX);
        q.push({src, 0});
        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                int from = q.front().first;
                int w = q.front().second;
                q.pop();
                for (auto p : g[from]) {
                    int to = p.first;
                    int wn = w + p.second;
                    if (wn > mini)  continue;
                    if (to == dst)
                        mini = min(mini, wn);
                    else if (wn < minCost[to]) {
                        q.push({to, wn});
                        minCost[to] = wn;
                    }
                }
            }
            if (k -- == 0)  break;
        }
        return mini == INT_MAX ? -1 : mini;
    }
};

// BFS
// 注意剪枝条件
