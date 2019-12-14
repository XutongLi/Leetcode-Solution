class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if (len == 0)
            return true;
        if (len % 2 != 0)
            return false;
        unordered_map<char, char> m;
        m[')'] = '(';   m[']'] = '[';   m['}'] = '{';
        m['('] = 'a';   m['['] = 'b';   m['{'] = 'c';
        stack<char> st;
        for (char c : s) {
            if (st.empty() || st.top() != m[c])
                st.push(c);
            else if (st.top() == m[c]) {
                st.pop();
            }
        }
        return st.empty();
    }
};