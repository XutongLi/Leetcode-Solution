class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;
        return !(num & (num - 1)) && (num - 1) % 3 == 0;
    }
};
// !num&(num-1)表示2的指数幂