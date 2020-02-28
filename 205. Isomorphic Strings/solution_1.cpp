class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int slen = s.size(), tlen = t.size();
        if (slen != tlen)
            return false;
        unordered_map<char, char> mp;
        unordered_set<char> mapped;
        for (int i = 0; i < slen; ++ i) {
            if (mp.find(t[i]) != mp.end()) {
                if (s[i] != mp[t[i]])
                    return false;
            }
            else if (mapped.find(s[i]) != mapped.end()) {
                return false;
            }
            else {
                mp[t[i]] = s[i];
                mapped.insert(s[i]);
            }
        }
        return true;
    }
};