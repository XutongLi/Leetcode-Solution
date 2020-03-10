class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2)
            return 1;
        vector<int> dp(n + 1, 0);
        for (int i = 3; i <= n; ++ i) {
            for (int j = 1; j <= i / 2; ++ j) {
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
            }
        }
        return dp[n];
    }
};
//dp time O(n^2)  space O(n)