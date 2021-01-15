class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int len = m + n;
        if (m == 0)
            return n % 2 == 1 ? nums2[n / 2] : (nums2[n / 2] + nums2[n / 2 - 1]) / 2.0;
        if (n == 0)
            return m % 2 == 1 ? nums1[m / 2] : (nums1[m / 2] + nums1[m / 2 - 1]) / 2.0;
        
        int left = -1, right = -1;
        int i = 0, j = 0, idx = 0;
        while (i < m && j < n && idx <= len / 2) {
            left = right;
            if (nums1[i] <= nums2[j])
                right = nums1[i ++];
            else
                right = nums2[j ++];
            idx ++;
        }
        while (i == m && idx <= len / 2) {
            left = right;
            right = nums2[j ++];
            idx ++;
        }
        while (j == n && idx <= len / 2) {
            left = right;
            right = nums1[i ++];
            idx ++;
        }
        
        if (len % 2 == 1)
            return right;
        else
            return (left + right) / 2.0;
    }
};

// O(m + n)