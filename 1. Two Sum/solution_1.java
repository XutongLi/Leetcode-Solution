class Solution {
    public int[] twoSum(int[] nums, int target) {
        if (nums.length == 0 || nums.length == 1)   
            return null;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int tmp = target - nums[i];
            if (map.containsKey(tmp))
                return new int[]{map.get(tmp), i};
            map.put(nums[i], i);
        }
        return null;
    }
}