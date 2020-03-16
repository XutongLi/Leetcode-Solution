class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size(), m = max(n1, n2);
        string str(m, '0');
        int cur = 0;
        for (int i = 1; i <= m; ++ i) {
            if (n1 - i >= 0)
                cur += num1[n1 - i] - '0';
            if (n2 - i >= 0)
                cur += num2[n2 - i] - '0';
            if (cur < 10) {
                str[m - i] = cur + '0';
                cur = 0;
            }
            else {
                cur -= 10;
                str[m - i] = cur + '0';
                cur = 1;
            }
        }
        if (cur == 1)
            return "1" + str;
        else
            return str;
    }
};
//time O(n)