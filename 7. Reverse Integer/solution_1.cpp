class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            int m = x % 10;
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && m > INT_MAX % 10)
                return 0;
            if (res < INT_MIN / 10 || res == INT_MIN / 10 && m < INT_MIN % 10)
                return 0;
            res = res * 10 + m;
            x /= 10;
        }
        return res;
    }
};