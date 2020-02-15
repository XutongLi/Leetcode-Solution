class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res(m + n, '0');
        for (int i = m - 1; i >= 0; -- i) {
            for (int j = n - 1; j >= 0; -- j) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0');
                res[i + j + 1] = sum % 10 + '0';
                res[i + j] += sum / 10;     //此步的中间结果可能不为数字
            }
        }
        for (int i = 0; i < m + n; ++ i) {
            if (res[i] != '0')
                return res.substr(i);
        }
        return "0";
    }
};
//num2   num2[0] num2[1] num2[2] num2[3]
//num1           num1[0] num1[1] num1[2]
//----------------------------------------
//       res[3]  res[4]  res[5]  res[6]
//res[2] res[3]  res[4]  res[5]  res[6]
//