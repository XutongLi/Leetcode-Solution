class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty())
            return 0;
        chars.push_back(127);   //为了处理最后一个字符
        int idx = 0, cnt = 1;
        char cur = chars[0];
        for (int i = 1; i < chars.size(); ++ i) {
            if (chars[i] != chars[i - 1]) {
                chars[idx ++] = cur;
                if (cnt > 1) {
                    string cstr = to_string(cnt);
                    for (char cs : cstr)
                        chars[idx ++] = cs;
                }
                cur = chars[i];
                cnt = 1;
            }
            else
                ++ cnt;
        }
        return idx;
    }
};
//time O(n)  space O(1)