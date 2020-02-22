class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 0)
            return 0;
        vector<long long> dp(n + 1);
        dp[1] = 1;
        int len = primes.size();
        vector<int> ptr(len, 1);    //primes中各个数字对应dp中的index
        for (int i = 2; i <= n; ++ i) {
            long long mini = INT_MAX;
            for (int j = 0; j < len; ++ j) {
                mini = min(mini, primes[j] * dp[ptr[j]]);
            }
            dp[i] = mini;
            for (int j = 0; j < len; ++ j) {
                if (primes[j] * dp[ptr[j]] == mini)
                    ++ ptr[j];
            }
        }
        return dp[n];
    }
};
//dp O(n * primes.size())