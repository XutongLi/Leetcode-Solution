class Solution {
    public int dominantIndex(int[] nums) {
        if (nums == null || nums.length < 2)    return 0;
        int max1 = nums[0] > nums[1] ? 0 : 1;
        int max2 = nums[0] > nums[1] ? 1 : 0;
        for (int i = 2; i < nums.length; i++) {
            if (nums[i] > nums[max1]) {
                max2 = max1;
                max1 = i;
            }
            else if (nums[i] > nums[max2]) {
                max2 = i;
            }
        }
        if (nums[max2] == 0 || nums[max1] / nums[max2] >= 2)
            return max1;
        else
            return -1;
    }
}