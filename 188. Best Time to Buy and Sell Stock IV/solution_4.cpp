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
        
        vector<int> sell(K + 1, 0);
        vector<int> buy(K + 1, prices[0]);
        for (int i = 1; i < n; ++ i) {
            for (int k = 1; k <= K; ++ k) {
                buy[k] = min(buy[k], prices[i] - sell[k - 1]);
                sell[k] = max(sell[k], prices[i] - buy[k]);
            }
        }
        return sell[K];
    }
};
//time O(nk) space O(k)
//通过含义：低价购入，高价卖出；将上一次交易的利润从本次购买的成本中出去，求得本次的利润就是总利润
//同solution_3：https://leetcode.com/submissions/detail/300427117/