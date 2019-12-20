class Solution {
public:
    int findKthLargest(vector<int>& input, int k) {
        int len = input.size();
        int lo = 0, hi = len - 1;
        int idx = partition(input, lo, hi);
        while (idx != k - 1) {
            if (idx > k - 1) {
                hi = idx - 1;
                idx = partition(input, lo, hi);
            }
            else {
                lo = idx + 1;
                idx = partition(input, lo, hi);
            }
        }
        return input[idx];
    }
    int partition(vector<int>& n, int lo, int hi) {
        if (lo >= hi)
            return lo;
        int idx = RandomInRange(lo, hi);
        swap(n[idx], n[hi]);
        int large = lo - 1;
        for (int i = lo; i < hi; i ++) {
            if (n[i] > n[hi]) {
                large ++;
                swap(n[i], n[large]);
            }
        }
        large ++;
        swap(n[hi], n[large]);
        return large;
    }
    int RandomInRange(int lo, int hi) {
        srand(time(NULL));
        return lo + rand() % (hi - lo + 1);
    }
    void swap(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }
};
