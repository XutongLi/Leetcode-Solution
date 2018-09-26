//o(n)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        k--;
        int lo = 0, hi = nums.length - 1;
        while (lo < hi) {
            int j = partition(nums, lo, hi);
            if (k < j) 
                hi = j - 1;
            else if (k > j)
                lo = j + 1;
            else
                return nums[j];
        }
        return nums[k];
    }
    private int partition(int[] nums, int lo, int hi) {
        int i = lo, j = hi + 1;
        int pivot = nums[lo];
        while (true) {
            while (nums[++i] > pivot) {
                if (i == hi)    break;
            }
            while (nums[--j] < pivot) {
                if (j == lo)    break;
            }
            if (i >= j) break;
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        return j;
    }
    private void swap(int nums[], int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}