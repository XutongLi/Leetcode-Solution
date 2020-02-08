class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++ i)
            for (int j = 1; j <= n; ++ j)
                if (grid[i - 1][j - 1] == 0)
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        return dp[m][n];
        
    }
};
//dp time O(mn) space O(mn)