class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int maxi = 0;
        for (int i = 1; i <= m; ++ i) {
            int pre = 0;
            for (int j = 1; j <= n; ++ j) {
                int tmp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    int tmp = dp[j];
                    dp[j] = min(min(dp[j - 1], pre), dp[j]) + 1;
                    pre = tmp;
                    maxi = max(maxi, dp[j]);
                }
                else {
                    dp[j] = 0;
                }
                pre = tmp;
            }
        }
        return maxi * maxi;
    }
};
//简化空间
// pre , old dp[j]
// dp[j - 1], new dp[j]