class Solution {
private:
    vector<int> panlin(const string &s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            -- i;
            ++ j;
        }
        return vector<int>{i, j};
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty())
            return res;
        unordered_map<int, vector<vector<string>>> mp;  //到idx为key时的回文串组成
        mp[0] = vector<vector<string>>{{s.substr(0, 1)}};
        for (int i = 1; i < s.size(); ++ i) {
            vector<int> idx = panlin(s, i, i);
            for (int k = 0; k <= (idx[1] - idx[0]) / 2 - 1; ++ k) {
                if (idx[0] + k < 0)
                    mp[idx[1] - 1 - k].push_back(vector<string>{s.substr(idx[0] + k + 1, idx[1] - idx[0] - 1 - 2 * k)});
                for (vector<string> prev : mp[idx[0] + k]) {
                    prev.push_back(s.substr(idx[0] + k + 1, idx[1] - idx[0] - 1 - 2 * k));
                    mp[idx[1] - 1 - k].push_back(prev);
                }
            }
            idx = panlin(s, i - 1, i);
            for (int k = 0; k <= (idx[1] - idx[0]) / 2 - 1; ++ k) {
                if (idx[0] + k < 0)
                    mp[idx[1] - 1 - k].push_back(vector<string>{s.substr(idx[0] + k + 1, idx[1] - idx[0] - 1 - 2 * k)});
                for (vector<string> prev : mp[idx[0] + k]) {
                    prev.push_back(s.substr(idx[0] + k + 1, idx[1] - idx[0] - 1 - 2 * k));
                    mp[idx[1] - 1 - k].push_back(prev);
                }
            }
        }
        return mp[s.size() - 1];
    }
};
//DP 