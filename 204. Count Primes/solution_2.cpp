class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> isPrime(n + 1, false);
        for (int i = 2; i < n; ++ i) {
            if (!isPrime[i]) {
                ++ res;
                for (int j = i; j <= n / i; ++ j)
                    isPrime[i * j] = true;
            }
        }
        return res;
    }
};
//https://leetcode.com/problems/count-primes/discuss/57588/My-simple-Java-solutionclass Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> isPrime(n + 1, false);
        for (int i = 2; i < n; ++ i) {
            if (!isPrime[i]) {
                ++ res;
                for (int j = i; j <= n / i; ++ j)
                    isPrime[i * j] = true;
            }
        }
        return res;
    }
};
//https://leetcode.com/problems/count-primes/discuss/57588/My-simple-Java-solution