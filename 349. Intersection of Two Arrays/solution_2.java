//36.7%
//先装入hashset，再判断
//O(n)
//set.contains()为O(1)操作
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set = new HashSet<>();
        HashSet<Integer> interSet = new HashSet<>();
        if (nums1.length == 0 || nums2.length == 0)
            return new int[0];
        for (Integer num : nums1) {
            set.add(num);
        }
        for (Integer num :nums2) {
            if (set.contains(num))
                interSet.add(num);
        }
        int[] res = new int[interSet.size()];
        int i = 0;
        for (Integer num : interSet)
            res[i++] = num;
        return res;
    }
}