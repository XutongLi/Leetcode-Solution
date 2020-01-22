class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size();
        int i = 0, j = 0, flag = -1, match;
        while (i < slen) {
            if (j < plen && p[j] == '*') {
                match = i;
                flag = j ++;
            }
            else if (j < plen && (s[i] == p[j] || p[j] == '?')) {
                ++ i;
                ++ j;
            }
            else if (flag >= 0) {
                i = ++ match;
                j = flag + 1;
            }
            else 
                return false;
        }
        while (j < plen && p[j] == '*') {
            ++ j;
        }
        return j == plen;
    }
};
//greedy
//O(s + p)