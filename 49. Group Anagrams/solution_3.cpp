class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty())
            return res;
        unordered_map<string, vector<string>> mp;
        for (string str : strs) {
            vector<int> vkey(26, 0);
            for (char s : str) {
                ++ vkey[s - 'a'];
            }
            string key;
            for (int i = 0; i < 26; ++ i) {
                key = key + string(vkey[i], i + 'a');
            }
            mp[key].push_back(str);
        }
        for (auto pair : mp) 
            res.push_back(pair.second);
        return res;
    }
};  //nk