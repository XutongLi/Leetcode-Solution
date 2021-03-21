class Solution {
public:
    int nthUglyNumber(int n, int A, int B, int C) {
        long l = 1, r = 2 * 1e9;
        long a = (long)A, b = (long)B, c = (long)C;
        long ab = a * b / __gcd(a, b);  // ab公倍数
        long ac = a * c / __gcd(a, c);
        long bc = b * c / __gcd(b, c);
        long abc = ab * c / __gcd(ab, c);
        
        while (l < r) {
            long m = (r - l) / 2 + l;
            long cnt = m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
            if (cnt < n)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
// O(log(1e9))
// f[m] = m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc
// 表示<=m的数中，可以被a、b、c整除的数的总量
// 参考 https://leetcode.com/problems/ugly-number-iii/discuss/387539/cpp-Binary-Search-with-picture-and-Binary-Search-Template