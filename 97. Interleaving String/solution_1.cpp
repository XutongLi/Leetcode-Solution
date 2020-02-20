class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3)
            return false;
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l3 + 1, false));
        dp[0][0] = true;
        for (int k = 1; k <= l3; ++ k) {
            for (int i = 0; i <= min(k, l1); ++ i) {
                int j = k - i;
                dp[i][k] = i > 0 && (s1[i - 1] == s3[k - 1]) && dp[i - 1][k - 1]
                        || j > 0 && j <= l2 && (s2[j - 1] == s3[k - 1]) && dp[i][k - 1];
            }
        }
        return dp[l1][l3];
    }
};
//dp time O(l1*l3) space O(l1*l3)
//dp[i][j][k]表示s1到第i个元素，s2到第j个元素，组合起来与s3到第k个元素匹配
//dp[i][j][k] = (s1[i-1]==s3[k-1]) && dp[i-1][j][k-1]
//            ||(s2[j-1]==s3[k-1]) && dp[i][j-1][k-1]       
//因为j=k-i，所以可优化为dp[i][k]，表示到s1第i个元素，s2到第k-i个元素，与s3到第k个元素匹配