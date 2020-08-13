class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++ i) {
            for (int l = 0; l < i; ++ l) 
                dp[i] += dp[l] * dp[i - l - 1];
        }
        return dp[n];
    }
};
//i为树的总节点数，l为左边个数，则i-l-1为右边个数