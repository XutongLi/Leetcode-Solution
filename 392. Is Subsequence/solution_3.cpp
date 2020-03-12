class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.size(), tl = t.size();
        if (s.size() > t.size())
            return false;
        int i = 0, j = 0;
        for (; i < sl; ++ i) {
            while (j < tl && s[i] != t[j])
                j ++;
            if (j == tl)
                break;
            ++ j;
        }
        return i == sl;
    }
};
//time O(sl + tl)  space O(1)