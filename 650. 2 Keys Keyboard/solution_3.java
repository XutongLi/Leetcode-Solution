//dynamic programming
class Solution {
    public int minSteps(int n) {
        if (n == 1) return 0;
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++)
            dp[i] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j < i; j++) {
                if (i % j == 0)
                    dp[i] = Math.min(dp[i], j + dp[i / j]);
            }
        }
        return dp[n];
    }
}