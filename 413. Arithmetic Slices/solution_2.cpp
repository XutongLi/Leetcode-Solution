class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)  return 0;
        int res = 0, cnt = 0;
        int gap = nums[1] - nums[0];
        for (int i = 2; i < n; ++ i) {
            if (nums[i] - nums[i - 1] == gap) {
                res += ++ cnt;
            }
            else {
                gap = nums[i] - nums[i - 1];
                cnt = 0;
            }
        }
        return res;
    }
};