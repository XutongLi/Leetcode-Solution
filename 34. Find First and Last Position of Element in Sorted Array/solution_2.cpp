class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {
                res[0] = mid;
                break;
            }
            else if (nums[mid] < target)
                lo = mid + 1;
            else 
                hi = mid - 1;
        }
        lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] != target)) {
                res[1] = mid;
                break;
            } 
            else if (nums[mid] > target)
                hi = mid - 1;
            else 
                lo = mid + 1;
        }
        return res;
    }
};