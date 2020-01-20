class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
    string decodeString(const string &s, int &i) {
        string res = "";
        while (i < s.size() && s[i] != ']') {
            if (!isdigit(s[i])) //不是数字，即是字母
                res += s[i ++];
            else {
                int num = 0;
                while (isdigit(s[i]))
                    num = num * 10 + s[i ++] - '0';
                ++ i;   //[
                string substr = decodeString(s, i);
                ++ i;   //]
                while (num --)
                    res += substr;
            }
        }
        return res;
    }
};
//每个括号内递归连成串