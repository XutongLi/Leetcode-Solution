class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        map<char, int> m;
        int res = 0;
        for (int i = 0, j = 0; j < len; j ++) {
            if (m.find(s[j]) != m.end()) {
                i = max(i, m[s[j]]);
            }
            res = max(res, j - i + 1);
            m[s[j]] = j + 1;
        }
        return res;
    }
};