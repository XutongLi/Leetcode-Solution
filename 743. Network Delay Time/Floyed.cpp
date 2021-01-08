// Floyed
class Solution {
private:
    const int INF = 1e9;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> g(N + 1, vector<int>(N + 1, INF));
        for (int i = 0; i <= N; ++ i)
            g[i][i] = 0;
        for (auto vec : times)
            g[vec[0]][vec[1]] = vec[2];

        for (int k = 1; k <= N; ++ k) {
            for (int i = 1; i <= N; ++ i) {
                for (int j = 1; j <= N; ++ j) {
                    if (g[i][k] + g[k][j] < g[i][j])
                        g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
        int res = *max_element(g[K].begin() + 1, g[K].end());
       return res == INF ? -1 : res;
    }
};
// O(V^3)