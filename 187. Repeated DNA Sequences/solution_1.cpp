class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> res;
        int n = s.size();
        if (n <= 10)
            return res;
        for (int i = 0; i <= n - 10; ++ i)
            ++ mp[s.substr(i, 10)];
        for (auto p : mp)
            if (p.second > 1)
                res.push_back(p.first);
        return res;
    }
};