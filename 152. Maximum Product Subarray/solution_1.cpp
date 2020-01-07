class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int maxi = nums[0], mini = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); ++ i) {
            int tmp = maxi;
            maxi = max(max(maxi * nums[i], mini * nums[i]), nums[i]);
            mini = min(min(tmp * nums[i], mini * nums[i]), nums[i]);
            res = max(res, maxi);
        }
        return res;
    }
};