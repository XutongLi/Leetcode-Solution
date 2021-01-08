// Naive Dijstra

class Solution {
private:
    const int INF = 1e9;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> g(N + 1, vector<int>(N + 1, INF));
        for (auto vec : times)
            g[vec[0]][vec[1]] = vec[2];
        
        vector<int> dis(N + 1, INF);
        vector<bool> vis(N + 1, false);
        dis[K] = 0;
        int minIdx = 0;
        for (int i = 1; i <= N; ++ i) {
            minIdx = 0;
            for (int j = 1; j <= N; ++ j) {
                if (!vis[j] && (minIdx == 0 || dis[j] < dis[minIdx]))
                    minIdx = j;
            }
            vis[minIdx] = true;
            for (int j = 1; j <= N; ++ j) {
                if (!vis[j] && dis[minIdx] + g[minIdx][j] < dis[j])
                    dis[j] = dis[minIdx] + g[minIdx][j];
            }
        }
        return dis[minIdx] == INF ? -1 : dis[minIdx];
    }

};

// O(v^2)