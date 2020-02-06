class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        int buy = prices[0], sell = 0, prev_sell = 0;
        for (int i = 1; i < n; ++ i) {
            int prev_buy = buy;
            buy = min(buy, prices[i] - prev_sell);
            prev_sell = sell;
            sell = max(sell, prices[i] - prev_buy);
        }
        return sell;
    }
};
//买时成本尽量小，卖时成本尽量大
//下一次购买时，将价格出去上次利润作为成本，最后算出的利润就是总利润
//空间复杂度优化为O(1)