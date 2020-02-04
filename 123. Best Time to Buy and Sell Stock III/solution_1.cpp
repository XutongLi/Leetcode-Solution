class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int K = 2, n = prices.size(), maxi = 0;
        vector<vector<int>> dp(K + 1, vector<int>(n, 0));
        for (int k = 1; k <= K; ++ k) {
            int tmp = dp[k - 1][0] - prices[0];
            for (int i = 1; i < n; ++ i) {
                dp[k][i] = max(dp[k][i - 1], prices[i] + tmp);
                tmp = max(tmp, dp[k - 1][i] - prices[i]);
            }
        }
        return dp[K][n - 1];
    }
};
//time O(kn)   space O(kn)
//k为买卖次数,i为天，dp[k][i]表示到第i天(不包括第i天)买卖最多k次最大收益
//dp[k, i] = max(dp[k, i - 1], prices[i] - prices[j] + dp[k - 1][j]) (0<=j<=i-1)
//         = max(dp[k, i - 1], prices[i] + max(dp[k - 1][j] - prices[j])) (0<=j<=i-1)
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39608/A-clean-DP-solution-which-generalizes-to-k-transactions
//空间复杂度优化 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution