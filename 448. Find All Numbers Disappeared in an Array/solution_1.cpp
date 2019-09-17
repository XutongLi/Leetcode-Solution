class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for (int i = 0; i < len; i ++) {
            nums[abs(nums[i]) - 1] = 0 - abs(nums[abs(nums[i]) - 1]);
        }
        for (int i = 0; i < len; i ++) {
            if (nums[i] > 0)
                res.push_back(i + 1);
        }
        return res;
    }
};