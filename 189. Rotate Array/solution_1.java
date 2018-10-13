class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        int tmp = 0;
        for (int i = 0; i < k; i++) {
            tmp = nums[len - 1];
            for (int j = len - 1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }
            nums[0] = tmp;
        }
    }
}