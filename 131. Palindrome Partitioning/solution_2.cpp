class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty())
            return res;
        unordered_map<int, vector<vector<string>>> mp;  //到idx为key时的回文串组成
        mp[0] = vector<vector<string>>{{s.substr(0, 1)}};
        for (int i = 1; i < s.size(); ++ i) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                -- l;   ++ r;
                if (l < 0)
                    mp[r - 1].push_back(vector<string>{s.substr(l + 1, r - l - 1)});
                for (vector<string> prev : mp[l]) {
                    prev.push_back(s.substr(l + 1, r - l - 1));
                    mp[r - 1].push_back(prev);
                }
            }
            l = i - 1, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                -- l;   ++ r;
                if (l < 0)
                    mp[r - 1].push_back(vector<string>{s.substr(l + 1, r - l - 1)});
                for (vector<string> prev : mp[l]) {
                    prev.push_back(s.substr(l + 1, r - l - 1));
                    mp[r - 1].push_back(prev);
                }
            }
        }
        //return mp[0];
        return mp[s.size() - 1];
    }
};
//DP O(n^2)
//对solution_1的优化