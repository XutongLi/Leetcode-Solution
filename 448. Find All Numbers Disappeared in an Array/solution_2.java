class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new LinkedList<>();
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            nums[(nums[i] - 1) % len] += len;
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] <= len)
                list.add(i + 1);
        }
        return list;
    }
}