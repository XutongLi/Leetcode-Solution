//O(nlogn) time
//O(1) space
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        int i = 0;
        while (true) {
            if (i == nums.length - 1 || nums[i] != nums[i + 1])
                return nums[i];
            else 
                i += 2;
        }
    }
}