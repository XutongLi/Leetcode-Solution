class Solution {
private:
    void getIsPalin(const string &s, vector<vector<bool>> &isPalin) {
        isPalin[0][0] = true;
        for (int i = 1; i < s.size(); ++ i) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                isPalin[l][r] = true;
                -- l; ++ r;    
            }
            l = i - 1; r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                isPalin[l][r] = true;
                -- l; ++ r;
            }
        }
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));    
        getIsPalin(s, isPalin);
        dp[0] = -1; //无划分
        for (int i = 1; i <= n; ++ i) {
            for (int k = 0; k <= i - 1; ++ k) {
                if (isPalin[k][i - 1])
                    dp[i] = min(dp[i], dp[k] + 1);
            }
        }
        return dp[n];
    }
};
//time O(n^2), space O(n^2)
//isPalin[i][j]表示s[i]-s[j]是回文的，先维护此数组，防止判断回文时重叠
//dp[n] 表示第n个及以前元素的最小划分数
//dp[n] = min(dp[k] + 1) if (s[k, i-1] is Palindrome) k = [0, i - 1]