//buyMaxProf[i]表示在i处卖的最大利益
//sellMaxProf[i]表示在i处买的最大利益
/*buyMaxProf[i]为buyMaxProf[i - 1]与sellMaxProf[i - 2] - price的最大值
 *前者为当前不买
 *后者为当前买(sellMaxProf[i - 2]为上一个买的，sellMaxProf[i - 1]为cooldown)
 */
/*sellMaxProf[i]为sellMaxProf[i - 1]与buyMaxProf[i - 1] + price的最大值
 *前者为当前不卖
 *后者为之前买
 */
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length <= 1) return 0;
        int len = prices.length;
        int[] buyMaxProf = new int[len + 1];
        int[] sellMaxProf = new int[len + 1];
        buyMaxProf[1] = -prices[0];
        sellMaxProf[1] = 0;
        for (int i = 2; i <= len; i++) {
            int price = prices[i - 1];
            buyMaxProf[i] = Math.max(buyMaxProf[i - 1], sellMaxProf[i - 2] - price);
            sellMaxProf[i] = Math.max(sellMaxProf[i - 1], buyMaxProf[i - 1] + price);
        }
        return sellMaxProf[len];
    }
}