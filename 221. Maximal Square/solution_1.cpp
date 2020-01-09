class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int maxi = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                }
                //matrix[i][j] == '1'
                else {
                    int nei_min = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                    if (nei_min == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = pow(sqrt(nei_min) + 1, 2);
                    }
                }
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 1 1 1

//dp
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 4 4
// 1 0 1 4 9 