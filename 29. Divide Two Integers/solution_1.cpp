class Solution {
    using ll = long long;
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        ll num1 = labs(dividend), num2 = labs(divisor), res = 0;
        while (num1 >= num2) {
            ll tmp = num2, cnt = 1;
            while (tmp << 1 <= num1) {
                tmp <<= 1;
                cnt <<= 1;
            }
            num1 -= tmp;
            res += cnt;
        }
        int flag = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        return flag * res;
    }
};
//O(logn * logn) 外层复杂度为O(logn)， 内层最大为O(logn)