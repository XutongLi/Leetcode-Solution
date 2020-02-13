class Solution {
private:
    int helper(vector<vector<int>> &dp, int l, int r) {
        if (l >= r)
            return 0;
        if (dp[l][r] > 0)
            return dp[l][r];
        int res = INT_MAX;
        for (int i = l; i <= r; ++ i) {
            int tmp = i + max(helper(dp, l, i - 1), helper(dp, i + 1, r));
            res = min(res, tmp);
        }
        dp[l][r] = res;
        return res;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return helper(dp, 1, n);
    }
};
//dp递归写法
//dp[i][j]表示i-j中，找出指定数的最少花费
//对i到j中每一个位置求以此位置首先猜测的最大花费，dp[i][j]就是这些最大花费的最小值
//图示：https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84794/DP-JAVA-O(n3)-Solution-With-Explanation-15ms-17-lines
//此题有Hard难度