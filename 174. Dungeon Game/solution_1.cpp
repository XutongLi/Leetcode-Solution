class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty())
            return 0;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        for (int i = m - 1; i >= 0; -- i) {
            for (int j = n - 1; j >= 0; -- j) {
                if (i == m - 1 && j == n - 1)
                    dp[i][j] = max(1 - dungeon[i][j], 1);
                else 
                    dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};
//dp time O(mn) space O(mn)
//dp[i][j]表示进入dungeon[i][j]时的血量