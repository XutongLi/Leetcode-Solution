class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty())      return false;
        unordered_set st(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int j = 1; j <= s.size(); ++ j) {
            for (int i = 0; i < j; ++ i) {
                dp[j] = dp[i] && (st.find(s.substr(i, j - i)) != st.end());
                if (dp[j])  break;
            }
        }
        return dp[s.size()];
    }
};
//dp[j] = dp[i] && s.substr(i, j - i) in wordDict