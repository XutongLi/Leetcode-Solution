class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), res = target >= 0 ? INT_MAX : INT_MIN;
        sort(nums.begin(), nums.end());
        bool has_res = false;
        for (int k = 0; k < n && !has_res; ++ k) {
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            int i = k + 1, j = n - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                int dis = abs(sum - target);
                res = dis < abs(res - target) ? sum : res;
                if (sum < target) 
                    ++ i;
                else if (sum > target)
                    -- j;
                else {
                    has_res = true;     //已有最小值0，不用再循环
                    break;
                }
            }
        }
        return res;
    }
};
//O(n^2)