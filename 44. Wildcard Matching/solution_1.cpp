class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size();
        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
        for (int i = slen; i >= 0; -- i) {
            for (int j = plen; j >= 0; -- j) {
                if (i == slen && j == plen)
                    dp[i][j] = true;
                else if (i == slen) {
                    if (p[j] != '*')
                        dp[i][j] = false;
                    else
                        dp[i][j] = dp[i][j + 1];
                }
                else if (s[i] == p[j] || p[j] == '?')
                    dp[i][j] = dp[i + 1][j + 1];
                else if (p[j] == '*')
                    dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                else
                    dp[i][j] = false;
            }
        }
        return dp[0][0];
    }
};
//类似于正则匹配 https://leetcode.com/problems/regular-expression-matching/
//将递归转化为dp

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        if (s.empty())
            return p[0] == '*' ? isMatch(s, p.substr(1)) : false;
        if (s[0] == p[0] || p[0] == '?')
            return isMatch(s.substr(1), p.substr(1));
        else if (p[0] == '*')
            return isMatch(s.substr(0), p.substr(1)) || isMatch(s.substr(1), p.substr(0));
        else
            return false;
    }
};

*/