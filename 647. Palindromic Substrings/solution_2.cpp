class Solution {
private:
    int expand(const string &s, int idx1, int idx2) {
        int i = idx1, j = idx2, cnt = 0;
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
            cnt += expand(s, i, i); //以当前数字开始数回文
            cnt += expand(s, i, i + 1); //以当前数字和下一数字开始数回文
        }
        return cnt;
    }
};
//O(n^2)
//将扩展计数函数合并为