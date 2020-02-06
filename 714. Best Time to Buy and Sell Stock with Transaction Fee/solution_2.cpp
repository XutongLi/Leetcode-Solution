class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        int buy = prices[0], sell = 0, pre_buy = prices[0];
        for (int i = 1; i < n; ++ i) {
            pre_buy = buy;
            buy = min(buy, prices[i] - sell);
            sell = max(sell, prices[i] - pre_buy - fee);
        }
        return sell;
    }
};
//dp time O(n)  space O(1)
//buy表示到每天的成本，尽可能少，抛去上一次交易的收益
//sell表示每天的收益，最后sell[n - 1]计算出的就是累计收益