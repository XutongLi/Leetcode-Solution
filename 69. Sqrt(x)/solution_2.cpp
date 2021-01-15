class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)	return 0;
        int l = 1, r = x;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (m <= x / m && (m + 1) > x / (m + 1))
                return m;
            else if (m > x / m)	
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};
