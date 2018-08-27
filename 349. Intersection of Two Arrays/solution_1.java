//99.79%
//O(n)
//hash table
//缺点：空间复杂度大
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1.length == 0 || nums2.length == 0 || nums1 == null || nums2 == null)
            return new int[0];
        int[] M = getM(nums1);
        int max = M[0];
        int min = M[1];
        boolean[] judge = new boolean[max - min + 1];
        for (int num : nums1) {
            judge[num - min] = true;
        }
        int i = 0;
        for (int num : nums2) {
            if (num >= min && num <= max && judge[num - min]) {
                judge[num - min] = false;
                nums1[i++] = num;
            }
        }
        return Arrays.copyOf(nums1, i);
    }
    public int[] getM(int[] nums) {
        int max = nums[0], min = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > max)
                max = nums[i];
            if (nums[i] < min)
                min = nums[i];
        }
        return new int[]{max, min};
    }
}