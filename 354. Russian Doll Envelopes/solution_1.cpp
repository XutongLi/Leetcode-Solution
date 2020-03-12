class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) 
            return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);
        dp[0] = 1;
        int maxi = 1;
        for (int i = 1; i < n; ++ i) {
            for (int j = 0; j < i; ++ j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
//dp 
//time O(n^2) space O(n)