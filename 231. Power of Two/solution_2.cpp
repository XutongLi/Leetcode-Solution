class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n &(n - 1)); 
    }
};
//如 !(1000 & 111)