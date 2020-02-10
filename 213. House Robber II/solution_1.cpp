class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())   return 0;
        int n = nums.size();
        if (n == 1)     return nums[0];
        if (n == 2)     return max(nums[0], nums[1]);
        vector<int> dpWith0(n, 0);  //可以从第0家开始，但是在n - 2家结束
        vector<int> dpWithout0(n, 0);   //不能从第0家开始，但是在n - 1家结束
        dpWith0[0] = nums[0];
        dpWith0[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++ i)
            dpWith0[i] = max(dpWith0[i - 1], dpWith0[i - 2] + nums[i]);
        dpWithout0[0] = 0;
        dpWithout0[1] = nums[1];
        for (int i = 2; i < n; ++ i)
            dpWithout0[i] = max(dpWithout0[i - 1], dpWithout0[i - 2] + nums[i]);
        return max(dpWith0[n - 2], dpWithout0[n - 1]);
    }
};
//dp time O(n) space O(n)
