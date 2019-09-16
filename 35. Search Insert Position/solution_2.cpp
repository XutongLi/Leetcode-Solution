class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        return binarySearch(nums, target, 0, len - 1);
    }
    int binarySearch(vector<int> nums, int target, int lo, int hi) {
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;
    }
};