class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty())
            return res;
        unordered_map<string, int> mp;
        for (string str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if (!mp.count(tmp)) {
                mp[tmp] = res.size();
                res.push_back({});
            }
            res[mp[tmp]].push_back(str);
        }
        return res;
    }
};  //nklogk