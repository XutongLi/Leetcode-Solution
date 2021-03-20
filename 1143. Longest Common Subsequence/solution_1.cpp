class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
// dp[i][j]表示到t1的第i个字符和到t2的第j个字符时，两者的最长公共子串长度
