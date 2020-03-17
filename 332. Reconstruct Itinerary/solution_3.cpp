class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> mp;  //multiset已按字典序排好
        for (auto &p : tickets)
            mp[p[0]].insert(p[1]);

        stack<string> st;
        st.push("JFK");
        while (!st.empty()) {
            string top = st.top();
            if (!mp[top].empty()) {
                st.push(*mp[top].begin());
                mp[top].erase(mp[top].begin());
            }
            else {
                res.push_back(top);
                st.pop();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//stack
//dfs的非递归写法