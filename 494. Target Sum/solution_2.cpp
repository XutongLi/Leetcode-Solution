class Solution {
private:
    int find(vector<int> &nums, int posi) {
        vector<int> dp(posi + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= nums.size(); ++ i) {
            for (int j = posi; j >= nums[i - 1]; -- j)
                dp[j] = dp[j] + dp[j - nums[i - 1]];
        }
        return dp[posi];
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