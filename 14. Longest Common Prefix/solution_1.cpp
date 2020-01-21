class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.empty())   return res;
        int idx = 0;
        for (auto c : strs[0]) {
            for (auto s : strs) {
                if (s[idx] != c)
                    return res;
            }
            res += c;
            ++ idx;
        }
        return res;
    }
};