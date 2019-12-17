class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int minidx = findMin(nums);
        return search(nums, minidx, target);
    }
    int search(vector<int>& nums, int minidx, int target) {
        int size = nums.size();
        int l = minidx, r = size + minidx - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int real_idx = mid >= size ? mid - size : mid;
            if (target == nums[real_idx])
                return real_idx;
            else if (target > nums[real_idx]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
    int findMin(vector<int> nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};//logn + logn