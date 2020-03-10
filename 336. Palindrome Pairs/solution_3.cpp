class Solution {
private:
    bool isP(string &s, int l, int r) {
        while (l < r) {
            if (s[l ++] != s[r --])
                return false;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); ++ i)
            mp[words[i]] = i;
        for (int i = 0; i < words.size(); ++ i) {
            for (int j = 0; j <= words[i].size(); ++ j) {
                if (isP(words[i], j, words[i].size() - 1)) {
                    string prefix = words[i].substr(0, j);     //前缀
                    reverse(prefix.begin(), prefix.end());
                    if (mp.find(prefix) != mp.end() && mp[prefix] != i)
                        res.push_back({i, mp[prefix]});
                }
                if (j > 0 && isP(words[i], 0, j - 1)) {
                    string suffix = words[i].substr(j);        //后缀
                    reverse(suffix.begin(), suffix.end());
                    if (mp.find(suffix) != mp.end() && mp[suffix] != i)
                        res.push_back({mp[suffix], i});
                }
            }
        }
        return res;
    }
};
//hash time O(n*k^2)