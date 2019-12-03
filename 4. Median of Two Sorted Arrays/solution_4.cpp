class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int len = m + n;
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0, hi = m;
        while (lo <= hi) {
            int i = (lo + hi) / 2;
            int j = (m + n + 1) / 2 - i;
            if (j > 0 && i < m && nums2[j - 1] > nums1[i])
                lo = i + 1;
            else if (i > 0 && j < n && nums1[i - 1] > nums2[j])
                hi = i - 1;
            else {
                int maxLeft = -1;
                if (i == 0)     maxLeft = nums2[j - 1];
                else if (j == 0)     maxLeft = nums1[i - 1];
                else    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                
                if (len & 1)    return maxLeft;
                
                int minRight = -1;
                if (i == m)     minRight = nums2[j];
                else if (j == n)    minRight = nums1[i];
                else    minRight = min(nums1[i], nums2[j]);
                
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};