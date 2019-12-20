class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        int l = 0, r = n - 1, res = 0;
        int lmax = height[0], rmax = height[n - 1];
        while (l < r) {
            if (height[l] <= height[r]) {
                height[l] >= lmax ? (lmax = height[l]) : res += (lmax - height[l]); 
                ++ l;
            }
            else {
                height[r] >= rmax ? (rmax = height[r]) : res += (rmax - height[r]);
                -- r;
            }
        }
        return res;
    }
};