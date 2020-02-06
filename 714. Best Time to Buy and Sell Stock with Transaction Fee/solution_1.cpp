class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        vector<int> buy(n, prices[0]);
        vector<int> sell(n, 0);
        for (int i = 1; i < n; ++ i) {
            buy[i] = min(buy[i - 1], prices[i] - sell[i - 1]);
            sell[i] = max(sell[i - 1], prices[i] - buy[i - 1] - fee);
        }
        return sell[n - 1];
    }
};
//dp
//buy表示到每天的成本，尽可能少，抛去上一次交易的收益
//sell表示每天的收益，最后sell[n - 1]计算出的就是累计收益