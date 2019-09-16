class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int n : nums)
            total += n;
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (sum * 2 == total - nums[i])
                return i;
            sum += nums[i];
        }
        return -1;
    }
};