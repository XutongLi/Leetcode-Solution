//20ms
//O(n^2)
class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
        int[] flag = new int[nums.length];
        flag[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            int count = 0;
            int flag_max = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    count++;
                    flag_max = Math.max(flag_max, flag[j]);
                }
            }
            flag[i] = Math.min(count, flag_max) + 1;
        }
        int max = 0;
        for (int i = 0; i < flag.length; i++) 
            max = Math.max(max, flag[i]);
        return max;
    }
}