class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        vector<int> st(n);
        int top = -1;
        for (int i = 0; i < n; ++ i) {
            while (top > -1 && T[i] > T[st[top]]) {
                res[st[top]] = i - st[top];
                -- top;
            }
            st[++ top] = i;
        }
        return res;
    }
};
//用vector表示stack