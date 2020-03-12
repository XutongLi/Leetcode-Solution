class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.size(), tl = t.size();
        if (sl > tl)
            return false;
        vector<int> dp(sl + 1, false);
        dp[0] = true;
        for (int i = 1; i <= tl; ++ i) {
            bool pre = dp[0];
            for (int j = 1; j <= sl; ++ j) {
                bool tmp = dp[j];
                dp[j] = dp[j] || (pre && t[i - 1] == s[j - 1]); 
                pre = tmp;
            }
        }
        return dp[sl];
    }
};
//dynamic programming  dp[i][j]表示到t的第i个字符（可不包括第i个），与到s的第i个字符匹配
//time O(sl*tl)  space O(sl)