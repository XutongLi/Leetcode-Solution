//20ms
//O(n^2)
class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
        int[] flag = new int[nums.length];
        int res = 1;
        flag[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            int max = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    max = Math.max(max, flag[j]);
                }
            }
            flag[i] = max + 1;
            res = Math.max(flag[i], res);
        }
        return res;
    }
}