class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) //起始处与终止处有障碍
            return 0;
        dp[0][0] = 1;
        for (int i = 1; i < m; ++ i) {    //左上到左下
            if (grid[i][0] == 1)
                break;
            else
                dp[i][0] = 1;
        }
        for (int j = 1; j < n; ++ j) {    //左上到右上
            if (grid[0][j] == 1)
                break;
            else
                dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++ i) {
            for (int j = 1; j < n; ++ j) {
                if (grid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
//dp time O(mn) space O(mn)