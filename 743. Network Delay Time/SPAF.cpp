// SPAF
class Solution {
private:
    const int INF = 1e9;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> g(N + 1, vector<int>(N + 1, INF));
        for (int i = 1; i <= N; ++ i)
            g[i][i] = 0;
        for (auto vec : times)
           g[vec[0]][vec[1]] = vec[2];
        vector<int> dis(N + 1, INF);
        vector<bool> inq(N + 1, false);
        vector<int> cnt(N + 1, 0);
        dis[K] = 0;
        queue<int> q;
        q.push(K);
        inq[K] = true;
        ++ cnt[K];
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            inq[from] = false;
            for (int to = 1; to <= N; ++ to) {
                if (dis[to] > dis[from] + g[from][to]) {
                    dis[to] = dis[from] + g[from][to];
                    if (!inq[to]) {
                        q.push(to);
                        inq[to] = true;
                        if (++ cnt[to] >= N);   // 有负环
                    }
                }
            }
        }
        int res = *max_element(dis.begin() + 1, dis.end());
        return res == INF ? -1 : res;
    }
};
// O(E)