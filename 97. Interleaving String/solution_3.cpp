class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3)
            return false;
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
        for (int i = 0; i <= l1; ++ i) {
            for (int j = 0; j <= l2; ++ j) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0) {
                    dp[i][j] = (s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1];
                }
                else if (j == 0) {
                    dp[i][j] = (s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j];
                } 
                else {
                    dp[i][j] = (s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1]
                            || (s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j];
                }
            }
        }
        return dp[l1][l2];
    }
};
//solution in discuss
//dp time O(l1 * l2) space O(l1 * l2)
//思路与自己方法一样（将dp[i][j][k]变为了dp[i][j], k=i+j）