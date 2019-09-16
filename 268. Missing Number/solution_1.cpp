class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for (int i = 0; i < len; i ++) 
            sum += nums[i];
        return (1 + len) * len / 2 - sum;
    }
};