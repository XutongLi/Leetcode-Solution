class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";
        unordered_map<char, int> cnt;
        unordered_map<char, int> window;
        int count = 0;
        string res = "";
        int mini = INT_MAX;
        for (char c : t)
            ++ cnt[c];
        for (int l = 0, r = 0; r < s.size(); ++ r) {
            if (cnt.find(s[r]) != cnt.end()) {
                ++ window[s[r]];
                if (window[s[r]] <= cnt[s[r]])
                    ++ count;
            }
            if (count == t.size()) {
                while (cnt.find(s[l]) == cnt.end() || window[s[l]] > cnt[s[l]]) {
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