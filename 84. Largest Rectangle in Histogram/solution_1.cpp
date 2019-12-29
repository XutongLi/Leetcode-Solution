class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        int j = 0, maxi = INT_MIN;
        while (j < n) {
            if (st.empty() || heights[j] > heights[st.top()])
                st.push(j ++);
            else {
                int h = heights[st.top()];
                st.pop();
                int i = st.empty() ? -1 : st.top();
                maxi = max(maxi, h * ( j - i - 1));
            }
        }
        return maxi;
    }
};//O(n)