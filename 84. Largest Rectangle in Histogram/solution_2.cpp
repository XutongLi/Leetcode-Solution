class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        int n = heights.size();
        vector<int> leftless(n, -1);
        for (int i = 1; i < n; ++ i) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i])
                p = leftless[p];
            leftless[i] = p;
        }
        vector<int> rightless(n, n);
        for (int i = n - 2; i >= 0; -- i) {
            int p = i + 1;
            while (p < n && heights[p] >= heights[i])
                p = rightless[p];
            rightless[i] = p;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; ++ i) {
            maxi = max(maxi, heights[i] * (rightless[i] - leftless[i] - 1));
        }
        return maxi;
    }
};//O(n)