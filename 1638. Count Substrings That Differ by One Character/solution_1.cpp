class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size(), cnt = 0, mini = min(m, n);
        int dp[m][n][mini + 1]; 
        for (int i = 0; i < m; ++ i) 
            for (int j = 0; j < n; ++ j)
                for (int k = 0; k < mini + 1; ++ k)
                    dp[i][j][k] = 0;
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                for (int k = 1; i + k <= m && j + k <= n; ++ k) {
                    if (dp[i][j][k - 1] == 2)
                        dp[i][j][k] = 2;
                    else if (s[i + k - 1] == t[j + k - 1] && dp[i][j][k - 1] == 1)
                        dp[i][j][k] = 1;
                    else if (s[i + k - 1] != t[j + k - 1] && dp[i][j][k - 1] == 0)
                        dp[i][j][k] = 1;
                    else if (s[i + k - 1] != t[j + k - 1] && dp[i][j][k - 1] == 1)
                        dp[i][j][k] = 2;
                    
                    if (dp[i][j][k] == 1)    ++ cnt;
                }
            }
        }
        return cnt;
    }
};
// dp O(n^3)
// dp[i][j][k]为 s由i位置开头长度为k的字串，t由j位置开头长度为k的字串
// dp=0代表两字串全相等，1代表只有一个字符不同，2代表有多个字符不同