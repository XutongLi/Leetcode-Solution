//dp
//100%
/**
 * max[0] = nums[0]
 * max[1] = max(nums[0], nums[1])
 * max[i] = max(max[i-1], max[i-2]+nums[i])
 **/
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0)   return 0;
        if (nums.length == 1)   return nums[0];
        int len = nums.length;
        int[] max = new int[len];
        max[0] = nums[0];
        max[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            max[i] = Math.max(max[i - 1], max[i - 2] + nums[i]);
        }
        return max[len - 1];
    }
}