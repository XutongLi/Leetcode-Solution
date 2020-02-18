class Solution {
public:
    bool isNumber(string s) {
        int idx = 0, n = s.size();
        bool hasE = false, hasDot = false, hasNum = false, isStart = true, endSpace = false;
        while (idx < n) {
            if (isspace(s[idx])) {
                if (!isStart)
                    endSpace = true;
                ++ idx;
            }
            else if (s[idx] == '+' || s[idx] == '-') {
                if (!isStart)
                    return false;
                isStart = false;
                ++ idx;
                if (idx == n)
                    return false;
                if (isdigit(s[idx])) { //+-后必跟数字
                    hasNum = true;
                    ++ idx;
                }
                else if (s[idx] == '.') {
                    ++ idx;
                    if (idx < n && isdigit(s[idx])) {
                        hasNum = true;
                        ++ idx;
                    }
                    else
                        return false;
                }
                else
                    return false;      
            }
            else if (s[idx] == '.') {
                if (endSpace || hasE || hasDot)
                    return false;
                ++ idx;
                hasDot = true;
                isStart = false;
                if (!hasNum) {
                    if (idx < n && isdigit(s[idx])) {
                        hasNum = true;
                        ++ idx;
                    }
                    else
                        return false;
                }
            }
            else if (s[idx] == 'e') {
                if (endSpace || !hasNum || hasE)
                    return false;
                hasE = true;
                ++ idx;
                if (idx == n)   //后必有数字
                    return false;
                if (s[idx] == '+' || s[idx] == '-') {
                    ++ idx;
                    if (idx < n && isdigit(s[idx]))  //+-后必跟数字
                        ++ idx;
                    else
                        return false;
                }
                else if (isdigit(s[idx]))
                    ++ idx;
                else
                    return false;
            }
            else if (isdigit(s[idx])) {  
                if (endSpace)
                    return false;
                isStart = false;
                hasNum = true;
                ++ idx;
            }
            else
                return false;
        }
        return isStart ? false : true;
    }
};
//空格 ：空格只在开头出现，非开头出现后endSpace标为true，后不能再出现别的元素
//+- ：只能出现在开头或E后，后必须跟数字，或先跟.再跟数字
//. ：之前不能有.和e，若之前没num则后面必须跟num
//e ：之前必须有num、不能有e，后必须有数字，或先跟+-再跟数字
//num ：不能出现在endSpace之后