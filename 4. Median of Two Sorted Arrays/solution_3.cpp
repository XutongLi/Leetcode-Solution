class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (getKth(nums1, 0, m - 1, nums2 , 0, n - 1, left) + getKth(nums1, 0, m - 1, nums2, 0, n - 1, right)) / 2.0;
    }
    
    int getKth(vector<int> nums1, int s1, int e1, vector<int> nums2, int s2, int e2, int k) {
        int l1 = e1 - s1 + 1;
        int l2 = e2 - s2 + 1;
        
        if (l1 == 0)    return nums2[s2 + k - 1];
        if (l2 == 0)    return nums1[s1 + k - 1];
        if (k == 1)     return min(nums1[s1], nums2[s2]);
        
        int i = min(e1, s1 + k / 2 - 1);
        int j = min(e2, s2 + k / 2 - 1);
        
        if (nums1[i] <= nums2[j])
            return getKth(nums1, i + 1, e1, nums2, s2, e2, k - (i - s1 + 1));
        else
            return getKth(nums1, s1, e1, nums2, j + 1, e2, k - (j - s2 + 1));
    }
};

// O(log(m + n))