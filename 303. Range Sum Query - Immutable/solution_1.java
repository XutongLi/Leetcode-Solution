class NumArray {
    private int[] num;
    public NumArray(int[] nums) {
        //num = new int[nums.length];
        num = Arrays.copyOf(nums, nums.length);
    }
    
    public int sumRange(int i, int j) {
        int sum = 0;
        for (int n = i; n <= j; n++)
            sum += num[n];
        return sum;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */