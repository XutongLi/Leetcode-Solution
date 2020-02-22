class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) 
            return 0;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        unordered_set<long long> st;
        q.push(1);
        int idx = 0;
        while (!q.empty()) {
            long long top = q.top();
            q.pop();
            if (st.find(top) != st.end())
                continue;
            ++ idx;
            if (idx == n)
                return top;
            st.insert(top);
            q.push(top * 2);
            q.push(top * 3);
            q.push(top * 5);
        }
        return 0;
    }
};
//O(nlogn)
//priority_queue + set