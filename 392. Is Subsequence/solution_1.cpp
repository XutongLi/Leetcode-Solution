class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.size(), tl = t.size();
        vector<vector<int>> dp(tl + 1, vector<int>(sl + 1, false));  
        for (int i = 0; i <= tl; ++ i)
            dp[i][0] = true;    //s为空串时，是t子串
        for (int i = 1; i <= tl; ++ i) {
            for (int j = 1; j <= sl; ++ j) {
                dp[i][j] = dp[i - 1][j] || (dp[i - 1][j - 1] && t[i - 1] == s[j - 1]); 
            }
        }
        return dp[tl][sl];
    }
};
//dynamic programming  dp[i][j]表示到t的第i个字符（可不包括第i个），与到s的第i个字符匹配
//time O(sl*tl)  space O(sl * tl)