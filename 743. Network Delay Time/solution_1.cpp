class Solution {
private:
    const int INF = 1e9;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
        for (auto vec : times) {
            graph[vec[0]][vec[1]] = vec[2];
        }
        
        vector<bool> exist(N + 1, false);
        vector<int> dis(N + 1, INF);
        dis[K] = 0;
        int minIdx = 0;
        for (int i = 1; i <= N; ++ i) {
            minIdx = 0;
            for (int j = 1; j <= N; ++ j) {
                if (!exist[j] && (minIdx == 0 || dis[j] < dis[minIdx]))
                    minIdx = j;
            }
            exist[minIdx] = true;
            for (int j = 1; j <= N; ++ j) {
                if (!exist[j] && dis[minIdx] + graph[minIdx][j] < dis[j])
                    dis[j] = dis[minIdx] + graph[minIdx][j];
            }
        }
        return dis[minIdx] == INF ? -1 : dis[minIdx];
    }
};
// Dijstra
// O(V^2)
