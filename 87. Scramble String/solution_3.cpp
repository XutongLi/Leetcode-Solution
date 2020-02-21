class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)   
            return true;
        int l1 = s1.size(), l2 = s2.size();
        if (l1 != l2)
            return false;
        vector<int> cnt(26, 0);
        for (int i = 0; i < l1; ++ i) {
            ++ cnt[s1[i] - 'a'];
            -- cnt[s2[i] - 'a'];
        }
        for (auto n : cnt) {
            if (n != 0)    //各字母有数量不同的
                return false;
        }
        vector<vector<vector<bool>>> dp(l1 + 1, vector<vector<bool>>(l1, vector<bool>(l1, false)));
        for (int l = 1; l <= l1; ++ l) {    //所有长度
            for (int i = 0; i <= l1 - l; ++ i) { //s1起始位置
                for (int j = 0; j <= l1 - l; ++ j) { //s2起始位置
                    if (l == 1)
                        dp[l][i][j] = (s1[i] == s2[j]);
                    else {
                        for (int s = 1; s < l; ++ s) {
                            dp[l][i][j] = dp[s][i][j] && dp[l - s][i + s][j + s]    //分隔后处理
                                || dp[s][i][j + l - s] && dp[l - s][i + s][j];   //分隔后先交换再处理
                            if (dp[l][i][j])
                                break;
                        }
                    }
                }
            }
        }
        return dp[l1][0][0];
    }
};
//dp time O(n^4) space O(n^3)
//每一部分分隔后有两种操作：1.做接下来的分隔与交换 2.先交换两部分，再做接下来的分隔与交换
//dp[len][i][j]表示s1[i,i+len-1]和s2[j,j+len-1]满足条件