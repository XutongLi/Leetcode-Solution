class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string res = "";
        string s = countAndSay(n - 1);
        int cnt = 1;
        char cur = s[0];
        for (int i = 1; i < s.size(); ++ i) {
            if (s[i] == s[i - 1]) {
                ++ cnt;
            }
            else {
                res = res + to_string(cnt) + cur;
                cur = s[i];
                cnt = 1;
            }
        }
        res = res + to_string(cnt) + cur;
        return res;
    }
};
