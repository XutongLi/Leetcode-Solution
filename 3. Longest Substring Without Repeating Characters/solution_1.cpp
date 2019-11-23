class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_set<char> se;
        int i = 0, j = 0, res = 0;
        while (i < len && j < len) {
            if (se.find(s[j]) == se.end()) {
                se.insert(s[j++]);
                res = max(res, j - i);
            }
            else
                se.erase(s[i++]);
        }
        return res;
    }
};