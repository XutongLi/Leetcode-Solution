class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3)
            return false;
        vector<bool> dp(l1 + 1, false);
        dp[0] = true;
        for (int k = 1; k <= l3; ++ k) {
            bool pre = dp[0];
            for (int i = 0; i <= min(k, l1); ++ i) {
                int j = k - i;
                bool tmp = dp[i];
                dp[i] = i > 0 && (s1[i - 1] == s3[k - 1]) && pre
                        || j > 0 && j <= l2 && (s2[j - 1] == s3[k - 1]) && dp[i];
                pre = tmp;
            }
        }
        return dp[l1];
    }
};
//dp time O(l1*l3) space O(l1)
//优化空间复杂度