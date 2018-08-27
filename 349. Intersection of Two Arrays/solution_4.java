//37%
//O(nlogn)
//binarySearch
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1.length == 0 || nums2.length == 0 || nums1 == null || nums2 == null)
            return new int[0];
        HashSet<Integer> set = new HashSet<>();
        Arrays.sort(nums2);
        for (int i = 0; i < nums1.length; i++) {
            int res = Arrays.binarySearch(nums2, nums1[i]);
            if (res >= 0)
                set.add(nums1[i]);
        }
        int[] result = new int[set.size()];
        int k = 0;
        for (int num : set) {
            result[k++] = num;
        }
        return result;
    }
}