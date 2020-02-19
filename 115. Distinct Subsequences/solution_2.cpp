class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size(), tlen = t.size();
        vector<vector<long long>> dp(slen + 1, vector<long long>(tlen + 1, 0));
        for (int i = 0; i <= slen; ++ i)
            dp[i][0] = 1;
        for (int i = 1; i <= slen; ++ i) {
            for (int j = 1; j <= tlen; ++ j) {
                dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[slen][tlen];
    }
};
//dp time O(st)  space O(st)
//dp[i][j] 表示s[0 - i-1]和t[0 - j-1]总的匹配数量
//t为空串时，s无论多长，匹配个数都为1
//dp[i][j] = dp[i - 1][j]   //s到第i个元素之前已经与t到j位置匹配
//          + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0)
                        //s第i个元素和t第j个元素相等时，加上s的第i个元素之前和t的第j个元素之前的匹配数目