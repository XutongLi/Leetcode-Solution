class Solution {
private:
    int maxExchangePro(const vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++ i) 
            res += max(prices[i] - prices[i - 1], 0);
        return res;
    }
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        if (K >= n / 2)     //尽可能多的交易
            return maxExchangePro(prices);
        
        vector<vector<int>> dp(K + 1, vector<int>(n, 0));
        for (int k = 1; k <= K; ++ k) {
            int tmp = prices[0];
            for (int i = 1; i < n; ++ i) {
                tmp = min(tmp, prices[i] - dp[k - 1][i - 1]);
                dp[k][i] = max(dp[k][i - 1], prices[i] - tmp);
            }
        }
        return dp[K][n - 1];
    }
};
//dp[k, i] 表示到第i天（第i天可能卖），最多交易k次的最大收益
//dp[k, i] = max(dp[k, i - 1], prices[i] - prices[j] + dp[k - 1, j - 1]) j = [0 - i]
//j的范围：[0 - i-1]--j买i卖，[i]--在i不做交易
//dp[k, i] = max(dp[k, i - 1], prices[i] - min(prices[j] - dp[k - 1, j - 1]))

//time O(nk)
//space O(nk)