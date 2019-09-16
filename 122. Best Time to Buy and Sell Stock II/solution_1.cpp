class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;
        int pro = 0;
        for (int i = 0; i < len - 1; i ++) {
            if (prices[i + 1] > prices[i])
                pro += prices[i + 1] - prices[i];
        }
        return pro;
    }
};