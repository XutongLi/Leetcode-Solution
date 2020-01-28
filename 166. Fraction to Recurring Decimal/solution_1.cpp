class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string res = "";
        if (numerator > 0 ^ denominator > 0)
            res += "-";
        long long num = labs(numerator), den = labs(denominator);
        res += to_string(num / den);
        num = num % den;
        if (num == 0)
            return res;
        res += ".";
        unordered_map<long long, int> mp;
        while (num > 0) {
            if (mp.find(num) != mp.end()) {     //余数已出现时，循环
                res.insert(res.begin() + mp[num], '(');
                res += ")";
                break;
            }
            mp[num] = res.size();
            num *= 10;
            res += to_string(num / den);
            num %= den;
        }
        return res;
    }
};