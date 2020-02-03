class Solution {
private:
    int helper(const string &s, int l, int r, int k) {
        if (r - l + 1 < k)
            return 0;
        vector<int> cnt(26, 0);
        for (int i = l; i <= r; ++ i)
            ++ cnt[s[i] - 'a'];
        bool pass = true;
        for (int i = 0; i < 26 && pass; ++ i) {
            if (cnt[i] > 0 && cnt[i] < k)
                pass = false;       
        }
        if (pass)
            return r - l + 1;       //此子串满足条件
        int maxi = 0, i = l;
        for (int j = l; j <= r; ++ j) {
            if (cnt[s[j] - 'a'] && cnt[s[j] - 'a'] < k) {       //以数量小于k的字符为分隔进行分治
                maxi = max(maxi, helper(s, i, j - 1, k));
                i = j + 1;
            }
        }
        return max(maxi, helper(s, i, r, k));
    }
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size() - 1, k);
    }
};
//divide and conquer O(26n)
//每个子串分别统计字符数量，以数量不足k的字符作为分隔进行分治
//最多对26个字母进行分隔，所以递归最多26层，每次进行遍历，复杂度为O(26n)