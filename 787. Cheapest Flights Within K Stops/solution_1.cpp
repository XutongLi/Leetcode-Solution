class Solution {
private:
    const int INF = 1e9;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto vec : flights)
            graph[vec[0]].push_back({vec[1], vec[2]});
        queue<pair<int, int>> q;
        q.push({src, 0});
        int res = INF;
        ++ K;
        while (K --) {
            int len = q.size();
            while (len --) {
                auto front = q.front();
                q.pop();
                int from = front.first, cur = front.second;
                for (auto p : graph[from]) {
                    int to = p.first, price = p.second;
                    if (cur + price > res)
                        continue;
                    q.push({to, cur + price});
                    if (to == dst)
                        res = cur + price;
                }
            }
        }
        return res == INF ? -1 : res;
    }
};
// BFS
// 此题中效率最高
