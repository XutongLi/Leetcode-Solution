class Solution {
private:
    int binarySearch(vector<int> &res, int n) {
        int l = 0, r = res.size() - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (res[m] == n)
                return m;
            if (res[m] > n)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
public:
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
    vector<int> LIS(vector<int>& arr) {
        vector<int> res;
        vector<int> mem;    // 记录arr中每个num插入res的位置
        for (int num : arr) {
            int pos = binarySearch(res, num);
            if (pos == res.size())
                res.push_back(num);
            else
                res[pos] = num;
            mem.push_back(pos);
        }
        for (int i = arr.size() - 1, j = res.size() - 1; i >= 0; -- i) {
            if (mem[i] == j)
                res[j --] = arr[i];
        }
        return res;
    }
};