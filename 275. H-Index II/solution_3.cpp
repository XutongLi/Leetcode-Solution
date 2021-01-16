class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int n = citations.size(), l = 0, r = n - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (citations[m] >= n - m && (m == 0 || citations[m - 1] < n - m + 1))
                return n - m;
            else if (citations[m] >= n - m)
                r = m - 1;
            else
                l = m + 1;
        }
        return 0;
    }
};
// O(logn)