//100%
//recursive solution
class Solution {
    public int search(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        return binarySearch(nums, lo, hi, target);
    }
    public int binarySearch(int[] nums, int lo, int hi, int target) {
        if (lo > hi)
            return -1;
        int mid = (lo + hi) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return binarySearch(nums, lo, mid - 1, target);
        else
            return binarySearch(nums, mid + 1, hi, target);
    }
}