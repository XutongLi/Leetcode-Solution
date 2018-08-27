//100%
//O(nlogn)
//sort + two pointers
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums1 == null || nums2 == null || nums1.length == 0 || nums2.length == 0)
            return new int[0];
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i = 0, j = 0, k = 0;
        int[] res = new int[Math.max(nums1.length, nums2.length)];
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else {
                res[k++] = nums1[i];
                i++;
                j++;
            }                         
        }
        return Arrays.copyOf(res, k);
    }
}