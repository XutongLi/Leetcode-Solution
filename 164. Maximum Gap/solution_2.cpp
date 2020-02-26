class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        vector<vector<int>> sort(10, vector<int>());
        int maxi = *max_element(nums.begin(), nums.end());
        int base = 1;
        while (maxi > 0) {
            for (auto n : nums)
                sort[(n / base) % 10].push_back(n);
            int idx = 0;
            for (auto vec : sort) {
                for (auto n : vec) 
                    nums[idx ++] = n;
            }
            base *= 10;
            maxi /= 10;
            sort.assign(10, vector<int>());
        }
        int res = 0;
        for (int i = 1; i < n; ++ i)
            res = max(res, nums[i] - nums[i - 1]);
        return res;
    }
};
//radix sort （基数排序）
//time O(dn) d为数字最大位数  space O(n + k) k为基数（10）
//https://leetcode.com/articles/maximum-gap/