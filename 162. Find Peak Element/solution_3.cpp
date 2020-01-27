class Solution {
private:
    int binarySearch(const vector<int> &nums, int l, int r) {
        if (l == r)
            return l;
        int mid = (r - l) / 2 + l;
        if (nums[mid] < nums[mid + 1])
            return binarySearch(nums, mid + 1, r);
        else 
            return binarySearch(nums, l, mid);
    }
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        return binarySearch(nums, l, r);
    }
};