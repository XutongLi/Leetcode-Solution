class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty())
            return res;
        int wnum = words.size(), wlen = words[0].size(), sublen = wnum * wlen, slen = s.size();
        if (slen < sublen)
            return res;
        unordered_map<string, int> mp;  //key - word, value - word num
        for (auto w : words)
            ++ mp[w];
        for (int l = 0; l <= slen - sublen; ++ l) {
            unordered_map<string, int> mem;
            bool match = true;
            for (int i = l; i <= l + sublen - wlen; i += wlen) {
                string sub = s.substr(i, wlen);
                if (mp.find(sub) == mp.end() || mem[sub] == mp[sub]) {  //没有此word或者数量超出，不匹配
                    match = false;
                    break;
                }
                ++ mem[sub];
            }
            if (match) 
                res.push_back(l);
        }
        return res;
    }
};
//time O(slen * wnum) space O(n)