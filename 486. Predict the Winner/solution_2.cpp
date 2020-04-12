class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, 0));
        for (int s = n - 1; s >= 0; -- s) {
            for (int e = s + 1; e < n; ++ e) {
                int pick_s = nums[s] - dp[s + 1][e];
                int pick_e = nums[e] - dp[s][e - 1];
                dp[s][e] = max(pick_s, pick_e);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
//dp (minmax question)
//time O(n^2)  space O(n^2)
//dp[s][e]表示当前player在[s,e]内与另一个player的得分差
//https://leetcode.com/articles/predict-the-winner/
//非递归写法