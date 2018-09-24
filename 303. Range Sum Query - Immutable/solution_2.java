class NumArray {
    private int[] num;
    public NumArray(int[] nums) {
        if (nums.length != 0) {
            num = new int[nums.length];
            num[0] = nums[0];
            for (int i = 1; i < nums.length; i++)
                num[i] = num[i - 1] + nums[i];
        }
    }
    
    public int sumRange(int i, int j) {
        if (i == 0) return num[j];
        return num[j] - num[i - 1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */