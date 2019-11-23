class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int res = 0;
        vector<int> map(128, -1);
        for (int i = 0, j = 0; j < len; j ++) {
            i = max(i, map[s[j]]);
            res = max(res, j - i + 1);
            map[s[j]] = j + 1;
        }
        return res;
    }
};