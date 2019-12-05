class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size() - 1;
        int maxi = 0;
        while (lo < hi) {
            maxi = max(maxi, min(height[lo], height[hi]) * (hi - lo));
            if (height[lo] < height[hi])
                lo ++;
            else
                hi --;
        }
        return maxi;
    }
};