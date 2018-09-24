//dp
//50%
//dp[i][1]表示第i元素被访问，dp[i][0]表示没被访问
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        if (cost == null || cost.length == 0)   return 0;
        if (cost.length == 1)   return cost[0];
        if (cost.length == 2)   return Math.min(cost[0], cost[1]);
        int len = cost.length;
        int[][] dp = new int[len][2];
        dp[0][0] = 0;
        dp[0][1] = cost[0];
        dp[1][0] = cost[0];
        dp[1][1] = cost[1];
        for (int i = 2; i < len; i++) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][1]) + cost[i];
        }
        return Math.min(dp[len - 1][0], dp[len - 1][1]);
    }
}