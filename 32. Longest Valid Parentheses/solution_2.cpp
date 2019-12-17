class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi = 0;
        vector<int> dp(s.size(), 0);    //init all 0 (d[i] = 0 when s[i] =='('
        for (int i = 1; i < s.size(); ++ i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                }
                else {  //i - 1] == '('
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] =='(') {
                        dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};