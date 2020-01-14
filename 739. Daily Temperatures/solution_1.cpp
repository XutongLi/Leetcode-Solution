class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        int n = T.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++ i) {
            while (!st.empty() && T[i] > T[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
//time O(n) space O(n)
//单调栈