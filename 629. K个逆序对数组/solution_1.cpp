class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++ i) {
            for (int j = 0; j <= min(k, i * (i - 1) / 2); ++ j) {
                if (j == 0)     dp[i][j] = 1;
                else 
                    dp[i][j] = (dp[i][j - 1] + (dp[i - 1][j] + MOD - (j >= i ? dp[i - 1][j - i] : 0)) % MOD) % MOD;
            }
        }
        return dp[n][k];
    }
};
// dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j - 2] + ... + dp[i - 1][j - i + 1]
// dp[i][j - 1] = dp[i - 1][j - 2] + ... + dp[i - 1][j - i]
// so dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - i]