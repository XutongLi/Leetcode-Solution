class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int i = 1; i <= n; ++ i) {
            for (int j = n; j > 0; -- j) {
                dp[i][j] = s[i - 1] == s[j - 1] ? dp[i - 1][j + 1] + 1 : max(dp[i - 1][j], dp[i][j + 1]);
            }
        }
        return dp[n][1];
    }
};
// dp[i][j]表示到整数第i个字符和倒数第j个字符时，最大的回文子序列