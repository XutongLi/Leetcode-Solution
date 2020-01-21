class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;
        int i = 0, num = 0;
        bool flag = true, has_num = false, has_sym = false;;
        while (i < str.size()) {
            if (isdigit(str[i])) {
                has_num = true;
                if (flag) {
                    if (num > INT_MAX / 10 || num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)
                        return INT_MAX;
                    num = str[i ++] - '0' + num * 10;
                        
                }
                else {
                    if (num < INT_MIN / 10 || num == INT_MIN / 10 && '0' - str[i] < INT_MIN % 10)
                        return INT_MIN;
                    num = '0' - str[i ++] + num * 10;
                }
            }
            else if (str[i] == ' ') {
                if (!has_num)
                    ++ i;
                else
                    break;
            }
            else if (str[i] == '-') {
                if (has_num)
                    break;
                flag = false;
                ++ i;
                if (!isdigit(str[i]))
                    return 0;
            }
            else if (str[i] == '+') {
                if (has_num)
                    break;
                flag = true;
                ++ i;
                if (!isdigit(str[i]))
                    return 0;
            }
            else 
                break;
        }
        return num;
        
    }
};