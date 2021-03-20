class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                dp[i][j] = str1[i - 1] == str2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        int i = m, j = n;
        string res = "";
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                res.push_back(str1[i - 1]);
                -- i;   -- j;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) { // 将相同字符后的字符加入res
                res.push_back(str1[i - 1]);
                -- i;
            }
            else {
                res.push_back(str2[j - 1]);
                -- j;
            }
        }
        while (i > 0) {
            res.push_back(str1[i - 1]);
            -- i;
        }
        // 将公共子串前的字符加入res
        while (j > 0) {
            res.push_back(str2[j - 1]);
            -- j;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};