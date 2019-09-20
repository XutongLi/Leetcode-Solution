class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1)
            return 0;
        vector<int> sell(len);
        vector<int> buy(len);
        buy[0] = 0 - prices[0];
        buy[1] = max(buy[0], 0 - prices[1]);
        sell[0] = 0;
        sell[1] = max(0, buy[0] + prices[1]);
        for (int i = 2; i < len; i ++) {
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
            buy[i] = max(sell[i - 2] - prices[i], buy[i - 1]);
        }
        return sell[len - 1];
    }
};