class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        //dp[i][j]表示第i个与第j个气球间所有扎法得到的最多硬币
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 1; len <= n; ++ len) {
            for (int i = 1; i <= n - len + 1; ++ i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++ k)   //k表示扎哪个气球
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]);
            }
        }
        return dp[1][n];
    }
};
//矩阵链乘法问题变种
//dp O(n^3)
//dp[i][j] = dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]