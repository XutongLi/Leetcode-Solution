class Solution {
    public int thirdMax(int[] nums) {
        long max1 = (long)Integer.MIN_VALUE - 1;
        long max2 = (long)Integer.MIN_VALUE - 1;
        long max3 = (long)Integer.MIN_VALUE - 1;
        for (int num : nums) {
            if (num == (int)max1 || num == (int)max2 || num == (int)max3) 
                continue;
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3) {
                max3 = num;
            }
        }
        return max3 != (long)Integer.MIN_VALUE - 1 ? (int)max3 : (int)max1;
    }
}