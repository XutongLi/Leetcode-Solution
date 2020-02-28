class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bitcnt = 0;
        while (m != n) {
            ++ bitcnt;
            m >>= 1;
            n >>= 1;
        }
        return m << bitcnt;
    }
};