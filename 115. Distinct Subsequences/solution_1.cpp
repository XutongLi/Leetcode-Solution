class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size(), tlen = t.size();
        vector<vector<long long>> dp(slen + 1, vector<long long>(tlen + 1, 0));
        dp[0][0] = 1;   
        for (int i = 1; i <= slen; ++ i) {
            for (int j = 1; j <= tlen; ++ j) {
                if (s[i - 1] != t[j - 1]) {
                    dp[i][j] = 0;
                    continue;
                }
                for (int k = j - 1; k <= i - 1; ++ k) {
                    dp[i][j] += dp[k][j - 1];
                }
            }
        }
        int res = 0;
        for (int i = tlen; i <= slen; ++ i)
            res += dp[i][tlen];
        return res;
    }
};
//dynamic programming 
//time O(s*t*s) space O(st)
//dp[i][j] 表示s[0 - i-1]与t[0 - j-1]匹配的方式数量
//dp[0][0] = 1，因为两个串为空时有一种匹配方式
//dp[i][j] = s[i - 1] != s[j - 1] ? 0 : sum(dp[k][j - 1]) k=[j-1, i-1] 