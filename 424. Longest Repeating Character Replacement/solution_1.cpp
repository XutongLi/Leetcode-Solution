class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxcharlen = 0;
        int st = 0;
        vector<int> cnt(26, 0);
        int res = 0;
        for (int end = 0; end < n; ++ end) {
            ++ cnt[s[end] - 'A'];
            maxcharlen = max(maxcharlen, cnt[s[end] - 'A']);
            while (end - st + 1 - maxcharlen > k) {
                -- cnt[s[st] - 'A'];
                ++ st;
                maxcharlen = 0;
                for (int i = 0; i < 26; ++ i) {
                    maxcharlen = max(maxcharlen, cnt[i]);
                }
            }
            res = max(res, end - st + 1);
        }
        return res;
    }
};
//sliding window(two pointers)
//time O(n)  space O(1)
//没有k限制情况下，使str只有一个字符的变换次数为 (n - 出现最多次数的字符的数量)
//加上k限制，则子串只含有一个字符最少变换次数为 (n - 子串出现次数最多字符的数量 <= k)