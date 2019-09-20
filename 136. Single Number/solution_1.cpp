class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if (len < 3)    return 0;
        vector<int> dp(len);
        dp[0] = 0;
        dp[1] = 1;
        int res = 0;
        int step = A[1] - A[0];
        for (int i = 2; i < len; i ++) {
            if (A[i] - A[i - 1] == step)
                dp[i] = dp[i - 1] + 1;
            else {
                dp[i] = 1;
                step = A[i] - A[i - 1];
            }
            if (dp[i] >= 2)
                res += dp[i] - 1;
        }
        return res;
    }
};