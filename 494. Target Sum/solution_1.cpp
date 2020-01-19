class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        helper(nums, S, 0, 0, res);
        return res;
    }
    void helper(const vector<int> &nums, int S, int idx, int sum, int &res) {
        if (idx == nums.size()) {
            if (sum == S)
                ++ res;
            return;
        }
        helper(nums, S, idx + 1, sum + nums[idx], res);
        helper(nums, S, idx + 1, sum - nums[idx], res);
    }
};
//back tracking
//O(2^n)