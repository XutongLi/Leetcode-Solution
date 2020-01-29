class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        for (int i = 2; i < n; ++ i) {
            bool isP = true;
            for (int k = 2; k <= sqrt(i); ++ k) {
                if (i % k == 0) {
                    isP = false;
                    break;
                }
            }
            if (isP)    ++ res;
        }
        return res;
    }
};