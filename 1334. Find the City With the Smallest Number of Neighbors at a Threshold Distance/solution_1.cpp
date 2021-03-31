class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long>> g(n, vector<long>(n, INT_MAX));
        for (int i = 0; i < n; ++ i)
            g[i][i] = 0;
        for (auto vec : edges) {
            g[vec[0]][vec[1]] = vec[2];
            g[vec[1]][vec[0]] = vec[2];
        }
        for (int k = 0; k < n; ++ k) {
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < n; ++ j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        int mini = INT_MAX, res = -1;
        for (int i = 0; i < n; ++ i) {
            int sum = 0;
            for (int j = 0; j < n; ++ j)
                if (g[i][j] > 0 && g[i][j] <= distanceThreshold)
                    ++ sum;
            if (sum <= mini) {
                mini = sum;
                res = i;
            }
        }
        return res;
    }
};
// Floyed
// O(V^3)