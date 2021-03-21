class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), l = 0, r = 0, res = 0;
        unordered_map<char, int> mp;
        for (r = 0; r < n; ++ r) {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// sliding window
// 遍历过程中，判断当前字符上一次出现的位置，若在l之后，则更新l