//1 2 3 4 5 6 7 k=2
//7 6 5 4 3 2 1
//6 7 5 4 3 2 1
//6 7 1 2 3 4 5
class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }
    private void reverse(int[] nums, int i, int j) {
        while (i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;    
            j--;
        }
    }
}