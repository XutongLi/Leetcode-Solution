class Solution {
public:
    bool isNumber(string s) {
        s.erase(0, s.find_first_not_of(" "));   //去掉首尾空格
        s.erase(s.find_last_not_of(" ") + 1);
        if (s.empty())
            return false;
        int idx = 0, n = s.size();
        bool hasNum = false, hasDot = false, hasE = false;
        while (idx < n) {
            if (s[idx] == '+' || s[idx] == '-') {
                if (!(idx == 0 || s[idx - 1] == 'e'))
                    return false;
                ++ idx;
                if (idx == n)
                    return false;
            }
            else if (isdigit(s[idx])) {
                hasNum = true;
                ++ idx;
            }
            else if (s[idx] == '.') {
                if (hasDot || hasE)
                    return false;
                hasDot = true;
                ++ idx;
                if (!hasNum && idx == n)
                    return false;
            }
            else if (s[idx] == 'e') {
                if (hasE || !hasNum)
                    return false;
                hasE = true;
                ++ idx;
                if (idx == n)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};
//剑指offer solution
//+- : 必须在s首或者e后，不能以+-结束
//. : 前面不能有.和e，若.前无数字，不能以.结尾
//e : 签名必须有数字，不能有e，不能以e结尾