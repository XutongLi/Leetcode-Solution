class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, maxi = 0;
        vector<int> mp(128, -1);
        for (int i = 0; i < s.size(); ++ i) {
            if (i - mp[s[i]] <= len) {
                len = i - mp[s[i] ];
            }
            else
                ++ len;
            maxi = max(maxi, len);
            mp[s[i]] = i;
        }
        return maxi;
    }
};
