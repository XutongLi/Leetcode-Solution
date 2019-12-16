class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
            return;
        int i = size - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            -- i;
        }
        if (i >= 0) {
            int j = size - 1;
            while (j > i && nums[j] <= nums[i]) {
                -- j;
            }
            swap(nums[i], nums[j]);
        }
        //reverse(nums.begin() + i + 1, nums.end());
        reverse(nums, i);
    }
    void reverse(vector<int> &nums, int start) {
        int i = start + 1;
        int j = static_cast<int>(nums.size() - 1);
        while (i < j) {
            swap(nums[i], nums[j]);
            ++ i;   -- j;
        }
    }
};