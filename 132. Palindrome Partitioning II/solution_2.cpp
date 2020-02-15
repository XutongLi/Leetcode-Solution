class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));    
        dp[0] = -1; //无划分
        for (int i = 0; i < n; ++ i) {
            for (int k = i; k >= 0; -- k) {
                if (s[i] == s[k] && (i - k < 2 || isPalin[k + 1][i - 1])) {
                    isPalin[k][i] = true;
                    dp[i + 1] = min(dp[i + 1], dp[k] + 1);
                }
            }
        }
        return dp[n];
    }
};
//time O(n^2), space O(n^2)
//discuss中的dp，一边构建idPalin，一边迭代dp