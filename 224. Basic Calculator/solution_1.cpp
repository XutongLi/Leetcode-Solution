class Solution {
private:
    int beg = 0, end = 0;
public:
    int calculate(string &s) {
        int i = beg, res = 0, num = 0, sign = 1;
        while (i < s.size()) {
            if (isdigit(s[i])) 
                num = num * 10  - '0' + s[i ++];
            else if (s[i] == '+' || s[i] == '-') {
                res += sign * num;
                num = 0;
                sign = (s[i] == '+') ? 1 : -1;
                ++ i;
            }
            else if (s[i] == '(') {
                beg = i + 1;
                num = calculate(s);
                i = end + 1;
            }
            else if (s[i] == ')') {
                end = i;
                res += sign * num;
                return res;
            }
            else    //空格
                ++ i;
        }
        //将最后一部分算入结果
        res += sign * num;
        return res;
    }
};
//DFS