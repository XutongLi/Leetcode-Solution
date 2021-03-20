class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 求lcs长度
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                dp[i][j] = str1[i - 1] == str2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        // 求lcs
        int i = m, j = n;
        string lcs = "";
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs.push_back(str1[i - 1]);
                -- i;   -- j;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) { 
                -- i;
            }
            else {
                -- j;
            }
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};
// 求LCS内容