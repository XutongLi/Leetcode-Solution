class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        buy[0] = prices[0];
        sell[0] = 0;
        buy[1] = min(buy[0], prices[1]);
        sell[1] = max(sell[0], prices[1] - buy[0]);
        for (int i = 2; i < n; ++ i) {
            buy[i] = min(buy[i - 1], prices[i] - sell[i - 2]);
            sell[i] = max(sell[i - 1], prices[i] - buy[i - 1]);
        }
        return sell[n - 1];
    }
};
//买时成本尽量小，卖时成本尽量大
//下一次购买时，将价格出去上次利润作为成本，最后算出的利润就是总利润