class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int sell1 = 0, sell2 = 0;
        for (int i = 0; i < prices.size(); ++ i) {
            buy1 = min(buy1, prices[i]);
            sell1 = max(sell1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - sell1);
            sell2 = max(sell2, prices[i] - buy2);
        }
        return sell2;
    }
};
//time O(n) space O(1)
//尽可能低价买入，高价售出；第二次买时将第一次利润从购买成本中出去，第二次所求的利润就是总的利润
//或者由k方法转换而来：https://leetcode.com/submissions/detail/300427117/