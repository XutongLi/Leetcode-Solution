class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<long long> dp(n + 1, 0);
        for (int i = 1; i <= m; ++ i) {
            if (i == 1) 
                dp[0] = 1;
            else
                dp[0] = 0;
            for (int j = 1; j <= n; ++ j) {
                if (grid[i - 1][j - 1] == 0)
                    dp[j] += dp[j - 1];
                else
                    dp[j] = 0;
            }
        }
        return dp[n];
    }
};
//dp time O(mn) space O(n)