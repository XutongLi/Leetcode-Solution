class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<long>> dp(nums.size() + 1, vector<long>(m + 1, LONG_MAX));
        vector<long> sum(nums.size() + 1, 0);
        
        for (int i = 0; i < nums.size(); ++ i) {
            sum[i + 1] = sum[i] + nums[i];
            dp[i + 1][1] = sum[i + 1];      //将前i+1个元素分为第一组的情况
        }
        
        for (int n = 2; n <= m; ++ n) {
            for (int i = n; i <= nums.size(); ++ i) {
                for (int j = n - 1; j < i; ++ j) {
                    dp[i][n] = min(dp[i][n], max(dp[j][n - 1], sum[i] - sum[j]));
                }
            }
        }
        return dp[nums.size()][m];
    }
};
//dp O(m*n^2) space O(mn)
//dp[i][n]表示到nums第i个数字，已分为m个子数组的最大子数组和 的最小值
