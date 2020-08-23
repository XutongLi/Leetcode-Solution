class Solution {
private:
    const int INF = 1e9;
    struct cmp {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        }
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> graph(N + 1);
        for (auto vec : times)
            graph[vec[0]].push_back({vec[1], vec[2]});
        
        vector<int> dis(N + 1, INF); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // dis, idx
        pq.push({0, K});
        dis[K] = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int from = top.second;
            for (auto p : graph[from]) {
                int to = p.first, time = p.second;
                if (dis[to] > dis[from] + time) {
                    dis[to] = dis[from] + time;
                    pq.push({dis[to], to});
                }
            }
        }
        int res = *max_element(dis.begin() + 1, dis.end());
        return res == INF ? -1 : res;
    }
};
// Dijstra + priority_queue
// O(ElogV)
