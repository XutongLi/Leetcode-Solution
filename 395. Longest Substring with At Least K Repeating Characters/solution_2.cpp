class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxi = 0;
        for (int repeatCharNum = 1; repeatCharNum <= 26; ++ repeatCharNum) {
            vector<int> cnt(26, 0);
            int l = 0, r = 0, nolessThanKNum = 0, existNum = 0;
            while (r < s.size()) {
                if (existNum <= repeatCharNum) {
                    int idx = s[r] - 'a';
                    if (cnt[idx] == 0)
                        ++ existNum;
                    ++ cnt[idx];
                    if (cnt[idx] == k)
                        ++ nolessThanKNum;
                    ++ r;
                }
                else {
                    int idx = s[l] - 'a';
                    if (cnt[idx] == k)
                        -- nolessThanKNum;
                    -- cnt[idx];
                    if (cnt[idx] == 0)
                        -- existNum;
                    ++ l;
                }
                if (existNum == repeatCharNum && nolessThanKNum == repeatCharNum)
                    maxi = max(maxi, r - l);
            }
        }
        return maxi;
    }
};
//two pointer O(26n)
//repeatCharNum为预设的子串中重复次数>=k的字符数量
//nolessThanKNum为一个子串中>=k数量
//existNum为子串中存在的字符数量
//算法思想：将子串中数量>=k的字符数量预设为1-26，分别使用双指针，当字符存在数量等于预设数量且>=k的数量等于预设数量时，计算一次长度
//此方法比较复杂，不如分治法直观