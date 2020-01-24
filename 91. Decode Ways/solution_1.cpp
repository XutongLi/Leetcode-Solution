class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;
        for (int i = 2; i <= n; ++ i) {
            int num1 = s[i - 1] - '0';
            int num2 = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            dp[i] = (num1 != 0 ? dp[i - 1] : 0)
                + ((num2 >= 10 && num2 <= 26) ? dp[i - 2] : 0);
        }
        return dp[n];
    }
};
//dp O(n)