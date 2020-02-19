class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size(), tlen = t.size();
        vector<long long> dp(tlen + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= slen; ++ i) {
            int pre = dp[0];
            for (int j = 1; j <= tlen; ++ j) {
                int tmp = dp[j];
                dp[j] = dp[j] + (s[i - 1] == t[j - 1] ? pre : 0);
                pre = tmp;
            }
        }
        return dp[tlen];
    }
};
//dp time O(st)  space O(t)
//优化空间复杂度
