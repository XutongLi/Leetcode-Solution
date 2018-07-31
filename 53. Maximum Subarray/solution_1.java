class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0], temp = 0;
        for (int i = 0; i < nums.length; i++) {
            if (temp > 0) {
                temp += nums[i];
            }
            else {
                temp = nums[i];
            }
            if (temp > sum) {
                sum = temp;
            }
        }
        return sum;
    }
}