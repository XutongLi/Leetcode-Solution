class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0)
            return;
        k = k % len;
        rotate(nums, 0, len - 1);
        rotate(nums, 0, k - 1);
        rotate(nums, k, len - 1);
    }
    void rotate(vector<int>& nums, int lo, int hi) {
        while (lo < hi) {
            int tmp = nums[lo];
            nums[lo] = nums[hi];
            nums[hi] = tmp;
            lo ++;  hi --;
        }
    }
};