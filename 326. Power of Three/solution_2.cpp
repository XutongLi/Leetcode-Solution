class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};
//n = 3^i
//logn = i*log3
//i = logn / log3