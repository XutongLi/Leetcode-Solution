class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";
        //unordered_map<char, int> cnt;
        //unordered_map<char, int> window;
        vector<int> cnt(128, 0);
        vector<int> window(128, 0);
        int count = 0;
        string res = "";
        int mini = INT_MAX;
        for (char c : t)
            ++ cnt[c];
        for (int l = 0, r = 0; r < s.size(); ++ r) {
            if (cnt[s[r]] != 0) {
                ++ window[s[r]];
                if (window[s[r]] <= cnt[s[r]])
                    ++ count;
            }
            if (count == t.size()) {
                while (cnt[s[l]] == 0 || window[s[l]] > cnt[s[l]]) {
                    -- window[s[l]];
                    ++ l;
                }
                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    res = s.substr(l, mini);
                }
            }
        }
        return res;
    }
};