class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 1)
            return true;
        int l = 1, r = num;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (m == num / m)
                return num % m == 0;
            else if (m < num / m)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }
};
//binary search
//time O(logn)