class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty())
            return res;
        unordered_map<string, vector<string>> mp;
        for (string str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }
        for (auto pair : mp) 
            res.push_back(pair.second);
        return res;
    }
};  //nklogk