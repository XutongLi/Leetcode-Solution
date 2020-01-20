class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int slen = s.size(), plen = p.size();
        if (slen < plen)  return res;
        vector<int> sv(26, 0), pv(26, 0);
        for (int i = 0; i < plen; ++ i) {
            ++ sv[s[i] - 'a'];
            ++ pv[p[i] - 'a'];
        }
        if (sv == pv)
            res.push_back(0);
        for (int i = plen; i < slen; ++ i) {
            -- sv[s[i - plen] - 'a'];
            ++ sv[s[i] - 'a'];
            if (sv == pv)
                res.push_back(i - plen + 1);
        }
        return res;
    }
};
//sliding window
//O(slen * 26)