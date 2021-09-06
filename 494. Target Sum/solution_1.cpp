class Solution {
private:
    int find(vector<int> &nums, int posi) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(posi + 1, 0));
        for (int i = 0; i <= nums.size(); ++ i)
            dp[i][0] = 1;
        for (int i = 1; i <= nums.size(); ++ i) {
            for (int j = 0; j <= posi; ++ j)
                dp[i][j] = dp[i - 1][j] + (j >= nums[i - 1] ? dp[i - 1][j - nums[i - 1]] : 0);
        }
        return dp[nums.size()][posi];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        target = abs(target);
        if (sum < target)   return 0;
        if ((sum + target) % 2 == 1)    return 0;
        return find(nums, (sum + target) / 2);
    }
};
// sum(p)为正数和，sum(n)为负数和
// sum(p) + sum(n) = target
// sum(p) - sum(n) = sum
// 2 * sum(p) = target + sum
// sum(p) = (target + sum) / 2
// 转化为求sum(p)有几种组合方式的问题
// 即0-1背包问题