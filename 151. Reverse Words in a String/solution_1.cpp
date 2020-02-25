class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        for (int i = 0; i < s.size(); ++ i) {
            if (isspace(s[i]))
                continue;
            int j;
            for (j = i + 1; j < s.size() && !isspace(s[j]); ++ j);
            res = s.substr(i, j - i) + (res.empty() ? "" : " " ) + res;
            i = j;
        }
        return res;
    }
};
//time O(n)  space O(1)