class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n < 0)      return 0;
        if (n == 0)     return 1;
        if (n == 1)     return 10;
        int cur = 9, k = 9, res = 10;   //cur为位数为i的不含重复位的数字，res为总数
        for (int i = 2; i <= n && k > 0; ++ i) {
            cur = cur * k;
            res += cur;
            k -= 1;
        }
        return res;
    }
};
//[0, 10^n)内不含重复位的数字
//排列组合 time O(n) space O(1)
//n = 1 --> 0 - 9
//n = 2 --> 10 12 13 ... 19   ...   91 92 ... 98 --> 9 * 9
//n = 3 -- > 9(不能为0) * 9(不能与第一位相同) * 8(不能与前两位相同)
//so on