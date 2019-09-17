class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                res[i][j] = getRes(M, i, j, m, n);
            }
        }
        return res;
    }
    int getRes(vector<vector<int>>& M, int row, int col, int m, int n) {
        int sum = 0;
        int cnt = 0;
        for (int i = -1; i <= 1; i ++) {
            for (int j = -1; j <= 1; j ++) {
                int x = row + i;
                int y = col + j;
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                cnt += 1;
                sum += M[x][y];
            }
        }
        return sum / cnt;
    }
};