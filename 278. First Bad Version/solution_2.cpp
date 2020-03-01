// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
private:
    int binary(int l, int r) {
        if (l == r)
            return l;
        int m = (r - l) / 2 + l;
        if (isBadVersion(m))
            return binary(l, m);
        else
            return binary(m + 1, r);
            
    }
public:
    int firstBadVersion(int n) {
        return binary(1, n);
    }
};
//binary search O(logn) 递归写法