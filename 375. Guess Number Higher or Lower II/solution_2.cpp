class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int j = 2; j <= n; ++ j) {
            dp[j - 1][j] = j - 1;
            for (int i = j - 2; i >= 0; -- i) {
                int mini = INT_MAX;
                for (int k = i + 1; k < j; ++ k) {
                    int tmp = k + max(dp[i][k - 1], dp[k + 1][j]);
                    mini = min(mini, tmp);
                }
                 dp[i][j] = mini;
            }
        }
        return dp[1][n];
    }
};
//dp O(n^3) 非递归
//dp[i][j]表示范围i-j猜中某数的最小花费
//k表示i-j中先猜错k的花费，先猜错k的花费为k + max(dp[i][k - 1], dp[k + 1][j])
//对所有k求花费最小值，就是i-j的猜中某数的最小花费
//图示：
//https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84794/DP-JAVA-O(n3)-Solution-With-Explanation-15ms-17-lines