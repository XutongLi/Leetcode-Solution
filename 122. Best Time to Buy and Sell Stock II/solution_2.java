//dp
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length <= 1) return 0;
        int len = prices.length;
        int[] buy = new int[len + 1];
        int[] sell = new int[len + 1];
        buy[1] = -prices[0];
        sell[1] = 0;
        for (int i = 2; i <= len; i++) {
            int price = prices[i - 1];
            buy[i] = Math.max(buy[i - 1], sell[i - 1] - price);
            sell[i] = Math.max(sell[i - 1], buy[i - 1] + price);
        }
        return sell[len];
    }
}