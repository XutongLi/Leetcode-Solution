class NumMatrix {
private:
    vector<vector<int>> cache;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0;
        cache.assign(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                cache[i + 1][j + 1] = matrix[i][j] + cache[i][j + 1] + cache[i + 1][j] - cache[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return cache[row2 + 1][col2 + 1] - cache[row1][col2 + 1]- cache[row2 + 1][col1] + cache[row1][col1];
    }
};
//time O(1)  space O(mn)
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */