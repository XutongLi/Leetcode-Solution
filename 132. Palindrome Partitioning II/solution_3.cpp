class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        for (int i = 0; i <= n; ++ i)
            dp[i] = i - 1;          //默认最大分割次数
        for (int i = 1; i < n; ++ i) {
            for (int j = 0; (i - j) >= 0 && (i + j) < n && s[i - j] == s[i + j]; ++ j)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
            for (int j = 0; (i - j - 1) >= 0 && (i + j) < n && s[i - j - 1] == s[i + j]; ++ j)
                dp[i + j + 1] = min(dp[i + j + 1], dp[ i - j - 1] + 1);
        }
        return dp[n];
    }
};
//Manancher-like solution
//dp[i]表示到第i个字符的最小分隔次数s[0]-s[i-1]
//https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42212/Two-C%2B%2B-versions-given-(one-DP-28ms-one-Manancher-like-algorithm-10-ms)