class Solution {
private:
    void dfs(unordered_map<string, multiset<string>> &mp, string &from, vector<string> &res) {
        while (!mp[from].empty()) {
            auto to = *mp[from].begin();
            mp[from].erase(mp[from].begin());
            dfs(mp, to, res);
        }
        res.push_back(from);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> mp;  //multiset已按字典序排好
        for (auto &p : tickets)
            mp[p[0]].insert(p[1]);

        string from = "JFK";
        dfs(mp, from, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
//dfs
//没有下一节点的先放入res，最后reverse
//https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B