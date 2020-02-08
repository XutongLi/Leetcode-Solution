class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (nums[m] == target)
                return true;
            else if(nums[m] == nums[r]) //1131
                -- r;
            else if (nums[m] < nums[r]) {
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
            else {
                if (nums[m] > target && target >= nums[l])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        return false;
    }
};
//binary search  time O(logn)
//worst O(n)