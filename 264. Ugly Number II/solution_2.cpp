class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0)
            return 0;
        vector<long long> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; ++ i) {
            dp[i] = min(2 * dp[p2], min(3 * dp[p3], 5 * dp[p5]));
            if (dp[p2] * 2 == dp[i])    ++ p2;
            if (dp[p3] * 3 == dp[i])    ++ p3;
            if (dp[p5] * 5 == dp[i])    ++ p5;
        }
        return dp[n];
    }
};
//dp O(n)