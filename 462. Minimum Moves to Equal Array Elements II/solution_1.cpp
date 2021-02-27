class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int res = 0;
        while (l < r) {
            res += nums[r] - nums[l];
            ++ l;
            -- r;
        }
        return res;
    }
};
// 每次将一个数+1或-1，求使所有数相等的最小操作次数
// 证明可得最后相等的数就是中位数
// nums[n-1] - C + nums[n - 2] - C + ... + C - nums[1] + C - nums[0]
// = nums[n-1] - nums[0] + nums[n-2] - nums[1] + ...
