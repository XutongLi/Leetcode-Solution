class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ = 0;
        int num = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 1) {
                num += 1;
            }
            else {
                max_ = max(max_, num);
                num = 0;
            }
        }
        return max(max_, num);
    }
};