class Solution {
private:
    bool dfs(int idx, long long num1, long long num2, int len1, int len2, const string &num) {
        if (num[idx] == '0')    //本数字开头为0，所以只能为0
            return num1 + num2 == 0;
        for (int len = max(len1, len2); len <= max(len1, len2) + 1; ++ len) {
            long long cur = stoll(num.substr(idx, len));
            if (cur != num1 + num2)
                continue;
            if (idx + len == num.size())
                return true;
            if (dfs(idx + len, num2, cur, len2, len, num))
                return true;
        }
        return false;
    }
public:
    bool isAdditiveNumber(string num) {
        long long num1 = 0, num2 = 0;
        //确定前两个数字
        for (int len1 = 1; 2 * len1 < num.size(); ++ len1) {
            num1 = stoll(num.substr(0, len1));
            for (int len2 = 1; len1 + len2 + max(len1, len2) <= num.size(); ++ len2) {
                num2 = stoll(num.substr(len1, len2));
                if (dfs(len1 + len2, num1, num2, len1, len2, num))
                    return true;
                if (num[len1] == '0')   //本数字开头为0，所以只能为0
                    break;
            }
        }
        return false;
    }
};
//dfs