class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string res = "";
        for (int i = num1.size() - 1; i >= 0; -- i) {
            int k = res.size() - (num1.size() - i - 1); //res后面不再改变的几位直接移过来
            string tmp = res.substr(k --);
            int a = num1[i] - '0';
            int carry = 0;  //进位
            for (int j = num2.size() - 1; j >= 0; -- j) {
                int b = num2[j] - '0';
                if (k >= 0) {
                    int c = res[k --] - '0';
                    tmp = to_string((a * b + c + carry) % 10) + tmp;
                    carry = (a * b + c + carry) / 10;
                }
                else {
                    tmp = to_string((a * b + carry) % 10) + tmp;
                    carry = (a * b + carry) / 10;
                }
            }
            if (carry != 0)
                tmp = to_string(carry) + tmp;
            res = tmp;
        }
        return res;
    }
};
//    8 7 2 3       num2 - b
//      4 5 6       num1 - a 
//--------------
//    4 3 3 8           
//  3 6 1 5           //逐行更新res，ab相乘后加res对应位
//2 8 9 2
//------------
//........8 8