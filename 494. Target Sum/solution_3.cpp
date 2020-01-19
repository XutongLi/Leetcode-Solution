class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> dp(nums.size() + 1);
        //idx第idx个数, key为到此idx的sum，val为到此idx的该sum的个数
        dp[0][0] = 1;   //初始化
        for (int i = 0; i < nums.size(); ++ i) {
            for (auto &pair : dp[i]) {
                dp[i + 1][pair.first + nums[i]] += pair.second;
                dp[i + 1][pair.first - nums[i]] += pair.second;
            }
        }
        return dp[nums.size()][S];
    }
};
//dp O(ns) n为nums.size, s为S