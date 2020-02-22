class Solution {
public:
    int calculate(string s) {
        int i = 0, res = 0, num = 0, sign = 1;
        stack<int> st;
        while (i < s.size()) {
            if (isdigit(s[i]))
                num = num * 10 - '0' + s[i];
            else if (s[i] == '+' || s[i] == '-') {
                res += sign * num;
                sign = (s[i] == '+') ? 1 : -1;
                num = 0;
            }
            else if (s[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;   //括号内重新计数
            }
            else if (s[i] == ')') {
                res += sign * num;
                res = st.top() * res;
                st.pop();
                res += st.top();
                st.pop();
                num = 0;
            }
            ++ i;
        }
        res += sign * num;  //补充s[-1]时为space或digit的数值（s[-1]为)时num为0）
        return res;
    }
};
//stack , no better than dfs