class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int l = 1, r = x;
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (mid < x / mid && (mid + 1) > x / (mid + 1))
                return mid;
            else if (mid < x / mid) {
                l = mid + 1;
            }
            else
                r = mid;
        }
        return l;
    }
};

/*
int mySqrt(int x) {
        if (x == 0) return 0;
        int n = 1;
        while (true) {
            if (n < x / n && (n + 1) > x / (n + 1))
                break;
            ++ n;
        }
        return n;
    }
*/