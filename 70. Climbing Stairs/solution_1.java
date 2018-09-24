//O(n)
//dp
//100%
//到达第n阶的路径数为到达第n-1阶路径数(再走一步)与到达第n-2阶路径数(再走两步)之和
//所以递推式为 dp[i]=dp[i-1]+dp[i-2]
class Solution {
    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}