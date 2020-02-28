class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long base = 1, floor, ceil;
        bool find_floor = false;
        while (true) {
            if (base > m && !find_floor) {
                floor = base >> 1;
                find_floor = true;
            }
            if (base > n) {
                ceil = base;
                break;
            }
            base = base << 1;
        }
        if ((floor << 1) < ceil) 
            return 0;
        long long res = m;
        for (long long i = static_cast<long long>(m) + 1; i <= static_cast<long long>(n); ++ i)
            res &= i;
        return res;
    }
};
//floor和ceil都为2的k次方，floor为<=m的最大值，ceil为>n的最小值
//当(floor << 1) < ceil时结果为0，否则逐个与运算