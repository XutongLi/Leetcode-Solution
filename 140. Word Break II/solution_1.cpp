class Solution {
private:
    void helper(const string &s, const unordered_set<string> &st, int idx, string &cur, vector<string> &res, int maxi) {
        if (idx == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = idx + 1; i <= min(static_cast<int>(s.size()), idx + maxi); ++ i) {
            string substr = s.substr(idx, i - idx);
            if (st.find(substr) == st.end())
                continue;
            string tmp = cur;
            cur = cur.empty() ? substr : cur + " " + substr;
            helper(s, st, i, cur, res, maxi);
            cur = tmp;
        }
    }
    bool canBreak(const string &s, const unordered_set<string> &st, int maxi) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++ i) {
            for (int j = i - 1; j >= max(0, i - maxi); -- j) {
                if (dp[j]) {
                    dp[i] = dp[j] && st.find(s.substr(j, i - j)) != st.end();
                    if (dp[i])  break;
                }
            }
        }
        return dp[s.size()];
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int maxi = 0;
        for (auto w : wordDict)
            maxi = max(maxi, static_cast<int>(w.size()));
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> res;
        if (!canBreak(s, st, maxi))
            return res;
        string cur = "";
        helper(s, st, 0, cur, res, maxi);
        return res;
    }
};
//back tracking
//先判断是否可分，以此降低极端情况下的复杂度，如：
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
//["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]