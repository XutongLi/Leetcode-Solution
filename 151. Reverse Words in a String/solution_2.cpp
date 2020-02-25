class Solution {
private:
    //翻转子串，并将其移动到合适位置
    void localrev(string &s, int beg, int end, int &idx) {
        int start = beg, len = end - start + 1;
        while (beg < end) {
            int tmp = s[beg];
            s[beg] = s[end];
            s[end] = tmp;
            ++ beg; -- end;
        }
        for (int i = 0; i < len; ++ i)
            s[idx ++] = s[start ++];
        s[idx ++] = ' ';
    }
public:
    string reverseWords(string s) {
        int idx = 0;
        for (int beg = 0; beg < s.size(); ++ beg) {
            if (isspace(s[beg]))
                continue;
            int end;
            for (end = beg + 1; end < s.size() && !isspace(s[end]); ++ end);
            localrev(s, beg, end - 1, idx);
            beg = end;
        }
        if (idx == 0)   //全是空格
            return "";
        s.resize(idx);
        reverse(s.begin(), s.end());
        return s.substr(1);
    }
};
//inplace solution
//time O(n) space O(1)