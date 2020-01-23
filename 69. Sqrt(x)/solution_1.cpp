class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) 
            return 0;
        double err = 1e-5;
        double n = static_cast<double>(x);
        while (fabs(n * n - x > err)) {
            n = (n + x / n) / 2.0;
        }
        return static_cast<int>(n);
    }
};
//newton
//O(logx)