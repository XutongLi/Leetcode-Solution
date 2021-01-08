// heap Dijstra
class Solution {
private:
    const int INF = 1e9;
    struct cmp {
        bool operator() (const pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first;
        }
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> g(N + 1);
        for (auto vec : times)
            g[vec[0]].push_back(make_pair(vec[1], vec[2]));
        
        vector<int> dis(N + 1, INF);
        vector<int> vis(N + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        dis[K] = 0;
        pq.push({0, K});

        while (!pq.empty()) {
            int minIdx = pq.top().second;
            pq.pop();
            if (vis[minIdx])	    continue;
            vis[minIdx] = true;
            for (auto p : g[minIdx]) {
                int to = p.first, wei = p.second;
                if (vis[to])	continue;
                dis[to] = min(dis[to], dis[minIdx] + wei);
                pq.push({dis[to], to});
            }
        }
        int res = *max_element(dis.begin() + 1, dis.end());
        return res == INF ? -1 : res;
    }
};
// O(VlogV+E)