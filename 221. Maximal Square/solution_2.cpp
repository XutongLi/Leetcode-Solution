class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int maxi = 0;
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi * maxi;
    }
};
//solution_1 dp存的是面积，此解法存的是边长
//通过m+1 ,n+1的数组，省去初始化操作