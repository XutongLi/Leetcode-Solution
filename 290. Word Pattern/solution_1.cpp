class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty() || str.empty())
            return false;
        stringstream ssm(str);
        int idx = 0;
        string tmp = "";
        unordered_map<char, string> mp;
        unordered_set<string> saved;
        while (idx < pattern.size() && getline(ssm, tmp, ' ')) {
            if (mp.find(pattern[idx]) != mp.end()) {
                if (mp[pattern[idx]] == tmp) {
                    ++ idx;
                }
                else
                    return false;
            }
            else {
                if (saved.find(tmp) != saved.end())
                    return false;
                else {
                    mp[pattern[idx ++]] = tmp;
                    saved.insert(tmp);
                }
            }
        }
        if (idx < pattern.size() || getline(ssm, tmp, ' ')) //两者长度不等
            return false;
        return true;
    }
};