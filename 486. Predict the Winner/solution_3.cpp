class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int s = n - 1; s >= 0; -- s) {
            for (int e = s + 1; e < n; ++ e) {
                int pick_s = nums[s] - dp[e];
                int pick_e = nums[e] - dp[e - 1];
                dp[e] = max(pick_s, pick_e);
            }
        }
        return dp[n - 1] >= 0;
    }
};
//dp (minmax question)
//time O(n^2)  space O(n)
//dp[s][e]表示当前player在[s,e]内与另一个player的得分差
//https://leetcode.com/articles/predict-the-winner/
//非递归写法
//优化空间复杂度