class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
        dp[slen][plen] = true;      //相当于s和p都是空串
        
        for (int i = slen; i >= 0; i --) {
            for (int j = plen - 1; j >= 0; j --) {
                bool firstMatch = (i < slen) && (s[i] == p[j] || p[j] == '.');
                if (j < plen - 1 && p[j + 1] == '*')
                    dp[i][j] = dp[i][j + 2] || firstMatch && dp[i + 1][j];
                else
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};