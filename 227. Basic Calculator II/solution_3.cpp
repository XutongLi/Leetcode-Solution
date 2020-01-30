class Solution {
public:
    int calculate(string s) {
        istringstream in("+" + s + "+");
        int res = 0, tmp = 0, num;
        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                res += tmp;
                in >> tmp;
                tmp *= (op == '+') ? 1 : -1;
            }
            else {
                in >> num;
                if (op == '*')
                    tmp *= num;
                else if (op == '/')
                    tmp /= num;
            }
        }
        return res;
    }
};