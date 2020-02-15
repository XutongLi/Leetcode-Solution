class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size(), n = b.size(), carry = 0;  //carry为进位
        for (int i = 0; i < max(m, n); ++ i) {
            int sum = carry;
            if (i < m)
                sum += a[m - i - 1] - '0';
            if (i < n)
                sum += b[n - i - 1] - '0';
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        if (carry == 1)
            res = "1" + res;
        return res;
    }
};