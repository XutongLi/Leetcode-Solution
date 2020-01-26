class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty())
            return res;
        unordered_map<int, vector<vector<string>>> mp;  //到idx为key-1时的回文串组成
        //mp[0] = vector<vector<string>>{{}};
        vector<vector<bool>> palin(s.size(), vector<bool>(s.size(), false));  //[i][j]表示s从i到j为回文
        for (int i = 0; i < s.size(); ++ i) {
            for (int l = 0; l <= i; ++ l) {
                if (s[l] == s[i] && (i - l <= 1 || palin[l + 1][i - 1])) {
                    palin[l][i] = true;
                    string str = s.substr(l, i - l + 1);
                    if (mp[l].empty())
                        mp[i + 1].push_back(vector<string>{str});
                    for (auto vec : mp[l]) {
                        vec.push_back(str);
                        mp[i + 1].push_back(vec);
                    }
                }
            }
        }
        return mp[s.size()];
    }
};
//DP O(n^2)
