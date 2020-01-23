class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (x == 0.0)
            return 0.0;
        if (n == INT_MIN) { 
            return myPow(x, n + 1) / x;
        }
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        return n % 2 ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
};
//O(logn)