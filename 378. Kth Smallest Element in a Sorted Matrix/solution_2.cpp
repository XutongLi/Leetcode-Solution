class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int l = matrix[0][0], r = matrix[m - 1][n - 1];
        while (l < r) {
            int mid = (r - l) / 2 + l;
            int cnt = 0;    //number of elements no bigger than mid
            for (auto m : matrix) {
                int cnt_row = upper_bound(m.begin(), m.end(), mid) - m.begin();
                cnt += cnt_row;
            }
            if (cnt < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
//bianry Search
//https://leetcode.com/uploads/files/1470276635988-upload-961f2cdd-6ecf-4ff2-af01-31c1e08eef89.png