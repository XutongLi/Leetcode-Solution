class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() <= 1)   
            return false;
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        //dp[i][j]意为前i个数字拿到总数j
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; ++ i) {
            dp[i][0] = true;    //无论多少背包都可拿到0
        }
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= sum; ++ j) {
                dp[i][j] = dp[i - 1][j];
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];  //此数字不取||此数字取
            }
        }
        return dp[n][sum];
    }
};
//o-1 背包问题 O(s*n)
//https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation