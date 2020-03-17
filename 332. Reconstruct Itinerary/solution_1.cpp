class Solution {
private:
    bool dfs(unordered_map<string, multiset<string>> &mp, string from, int len, vector<string> &res) {
        if (len == 0)
            return true;
        auto tmp = mp;
        for (auto &to : mp[from]) {
            res.push_back(to);
            auto it = tmp[from].find(to);
            tmp[from].erase(it);
            if (dfs(tmp, to, len - 1, res))
                return true;
            tmp[from].insert(to);
            res.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> mp;  //multiset已按字典序排好
        for (auto &p : tickets)
            mp[p[0]].insert(p[1]);
        
        int len = tickets.size();
        string from = "JFK";
        res.push_back(from);
        dfs(mp, from, len, res);
        return res;
    }
};
//backtracking