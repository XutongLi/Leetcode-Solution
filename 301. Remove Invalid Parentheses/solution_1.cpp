class Solution {
private:
    bool isValid(const string &s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '(')
                st.push(c);
            else if (c == ')') {
                if (st.empty())
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }    
    void helper(string &s, int idx, vector<string> &res) {
        if (isValid(s)) {
            res.push_back(s);
            return;
        }
        while (idx < s.size()) {
            while (idx < s.size() && s[idx] != '(' && s[idx] != ')')
                ++ idx;
            if (idx == s.size())
                return;  
            char tmp = s[idx];
            s.erase(idx, 1);
            helper(s, idx, res);
            s.insert(s.begin() + idx, tmp);
            while (idx < s.size() - 1 && s[idx + 1] == s[idx])    //去除重复
                ++ idx;   
            ++ idx;
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> tmp;
        helper(s, 0, tmp);
        if (tmp.empty()) {
            string alpha = "";
            for (auto c : s) {
                if (c != '(' && c != ')')
                    alpha += c;
            }
            tmp.push_back(alpha);
            return tmp;
        }
        int maxi = INT_MIN;
        for (auto str : tmp) {
            maxi = max(maxi, static_cast<int>(str.size()));
        }
        vector<string> res;
        for (auto str : tmp) {
            if (str.size() == maxi)
                res.push_back(str);
        }
        return res;
    }
};
//normal DFS