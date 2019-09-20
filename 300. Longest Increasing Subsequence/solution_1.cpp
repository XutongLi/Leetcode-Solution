class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)   return 0;
        int res = 1;
        vector<int> flag(len, 1);
        // flag[0] = 1;
        for (int i = 1; i < len; i ++) {
            int maxi = 0;
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    maxi = max(maxi, flag[j]);
                }
            }
            flag[i] = maxi + 1;
            res = max(res, flag[i]);
        }
        return res;
    }
};