class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{searchLeft(nums, target), searchRight(nums, target)};
    }
    int searchLeft(vector<int> nums, const int &target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] < target)
                    return mid;
                else
                    r = mid - 1;
            }
            else if (nums[mid] > target) 
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int searchRight(vector<int> nums, const int &target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || nums[mid + 1] > target)
                    return mid;
                else
                    l = mid + 1;
            }
            else if (nums[mid] > target) 
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};