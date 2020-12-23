class Solution {
private:
    const int INF = 1e9;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(K + 2, vector<int>(n, INF));
        for (int i = 0; i <= K + 1; ++ i)
            dp[i][src] = 0;
        for (int i = 1; i <= K + 1; ++ i) {
            for (auto v : flights) {
                dp[i][v[1]] = min(dp[i][v[1]], dp[i - 1][v[0]] + v[2]);
            }
        }
        return dp[K + 1][dst] == INF ? -1 : dp[K + 1][dst];
    }
};
// Bellman-Ford
// O(K*E)
