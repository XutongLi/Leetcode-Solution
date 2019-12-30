class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int maxi = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (matrix[i][j] == '1')
                    ++ height[j];
                else
                    height[j] = 0;
            }
            maxi = max(maxi, maxArea(height));
        }
        return maxi;
    }
    int maxArea(vector<int> &height) {
        if (height.empty())
            return 0;
        int maxi = 0, i = 0;
        height.push_back(0);
        stack<int> st;
        while (i < height.size()) {
            if (st.empty() || height[i] > height[st.top()]) {
                st.push(i ++);
            }
            else {
                int top = st.top();
                st.pop();
                int j = st.empty() ? -1 : st.top();
                maxi = max(maxi, height[top] * (i - j - 1));
            }
        }
        return maxi;
    }
};
//每一次循环化为 84. Largest Rectangle in Histogram