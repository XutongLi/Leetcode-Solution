class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int num = 0;
        stack<pair<int, string>> st;    //first为左括号外数量，second为左括号外字符串
        for (char c : s) {
            if (isdigit(c))
                num = num * 10 + c - '0';
            else if (isalpha(c))
                res += c;
            else if (c == '[') {
                st.push(make_pair(num, res));
                res = "";
                num = 0;
            }
            else {  //c == ']'
                string tmp = res;
                auto p = st.top();
                st.pop();
                for (int i = 0; i < p.first - 1; ++ i)
                    res += tmp;
                res = p.second + res;
            }
        }
        return res;
    }
};