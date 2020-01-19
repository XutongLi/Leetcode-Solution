class Solution {
private:
    int cntfromsingle(const string &s, int idx) {
        int i = idx, j = idx, cnt = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            ++ cnt;
            -- i;
            ++ j;
        }
        return cnt;
    }
    int cntfromdouble(const string &s, int idx) {
        if (idx == s.size() - 1)
            return 0;
        int i = idx, j = idx + 1, cnt = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            ++ cnt;
            -- i;
            ++ j;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        if (s.empty())  return 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++ i) {
            cnt += cntfromsingle(s, i); //以当前数字开始数回文
            cnt += cntfromdouble(s, i); //以当前数字和下一数字开始数回文
        }
        return cnt;
    }
};
//O(n^2)