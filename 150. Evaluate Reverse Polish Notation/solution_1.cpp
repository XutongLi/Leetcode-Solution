class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;
        if (tokens.size() == 1)
            return stoi(tokens[0]);
        stack<int> st;
        st.push(0);
        int res = 0;
        for (auto s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s!= "/")
                st.push(stoi(s));
            else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (s == "+") 
                    res = a + b;
                else if (s == "-")
                    res = a - b;
                else if (s == "*")
                    res = a * b;
                else if (s == "/")
                    res = a / b;
                st.push(res);
            }
        }
        return res;
    }
};