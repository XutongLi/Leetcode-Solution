class Solution {
private:
    vector<string> helper(const string &s, int idx, const unordered_set<string> &st, unordered_map<int, vector<string>> &cache, int maxi) {
        if (cache.find(idx) != cache.end())
            return cache[idx];
        for (int i = idx + 1; i <= min(static_cast<int>(s.size()), idx + maxi); ++ i) {
            string substr = s.substr(idx, i - idx);
            if (st.find(substr) == st.end())
                continue;
            if (i == s.size()) {
                cache[idx].push_back(substr);
            }
            else {
                vector<string> tmp = helper(s, i, st, cache, maxi);
                for (auto str : tmp) {
                    cache[idx].push_back(substr + " " + str);
                }
            }
            
        }
        return cache[idx];
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int maxi = 0;
        for (auto w : wordDict)
            maxi = max(maxi, static_cast<int>(w.size()));
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> cache;
        return helper(s, 0, st, cache, maxi);
    }
};
//DFS with memo (DFS + DP)