class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int l = 0, n = citations.size(), r = n - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (citations[m] > n - m)
                r = m - 1;
            else if (citations[m] < n - m)
                l = m + 1;
            else
                return n - m;
        }
        return n - l;
    }
};
//binary search O(logn)