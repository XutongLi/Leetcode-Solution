class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, cur = 0;
        stack<int> st;
        while (cur < height.size()) {
            while (!st.empty() && height[cur] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int dis = cur - st.top() - 1;
                res = res + (min(height[st.top()], height[cur]) - height[top]) * dis;
            }
            st.push(cur ++);
        }
        return res;
    }
};