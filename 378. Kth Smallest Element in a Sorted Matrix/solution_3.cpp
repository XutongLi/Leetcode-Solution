class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int l = matrix[0][0], r = matrix[m - 1][n - 1];
        while (l < r) {
            int mid = (r - l) / 2 + l, j = n - 1, cnt = 0;  // cnt为<=mid的数量
            for (int i = 0; i < m; ++ i) {
                while (j >= 0 && matrix[i][j] > mid) -- j;
                cnt += j + 1;
            }
            if (cnt < k)    l = mid + 1;
            else    r = mid;
        }
        return l;
    }
};
// O((m+n)log(max(num)))