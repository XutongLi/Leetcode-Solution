class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char flag = '+';
        int res = 0, tmp = 0;
        for (int i = 0; i < s.size(); ++ i) {
            if (isdigit(s[i])) {
                tmp = tmp * 10  - '0' + s[i];
            }
            if (!isdigit(s[i]) && !isspace(s[i]) || i == static_cast<int>(s.size()) - 1) {
                if (flag == '+')
                    st.push(tmp);
                else if (flag == '-')
                    st.push(0 - tmp);
                else if (flag == '*') {
                    int num = st.top();
                    st.pop();
                    st.push(num * tmp);
                }
                else { // /
                    int num = st.top();
                    st.pop();
                    st.push(num / tmp);
                }
                flag = s[i];
                tmp = 0;
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};