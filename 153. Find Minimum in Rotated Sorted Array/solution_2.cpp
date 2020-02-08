class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (nums[m] > nums[r])
                l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};
//O(logn)
//结束循环时l == r