class Solution {
public:
    bool isNumber(string s) {
        s.erase(0, s.find_first_not_of(" "));   //去掉首尾空格
        s.erase(s.find_last_not_of(" ") + 1);
        if (s.empty())
            return false;
        int n = s.size(), state = 0;
        for (int i = 0; i < n; ++ i) {
            if (s[i] == '+' || s[i] == '-') {
                if (state == 0)     state = 1;
                else if (state == 4)    state = 6;
                else    return false;
            }
            else if (isdigit(s[i])) {
                if (state <= 2)     state = 2;
                else if (state == 7 || state == 8)    state = 8;
                else if (state == 3)    state = 3;
                else if (state >= 4 && state <= 6)  state = 5;
                else    return false;
            }
            else if (s[i] == '.') {
                if (state == 0 || state == 1)   state = 7;
                else if (state == 2)    state = 3;
                else    return false;
            }
            else if (s[i] == 'e') {
                if (state == 2 || state == 3 || state == 8) state = 4;
                else return false;
            }
            else
                return false;
        }
        return state == 2 || state == 3 || state == 5 || state == 8;
    }
};
//DFA