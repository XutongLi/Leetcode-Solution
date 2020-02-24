class NumMatrix {
private:
    vector<vector<int>> cache;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0;
        cache = matrix;
        for (int i = 0; i < m; ++ i) {
            for (int j = 1; j < n; ++ j) {
                cache[i][j] += cache[i][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i = row1; i <= row2; ++ i)
            res += cache[i][col2] - ((col1 == 0) ? 0 :  cache[i][col1 - 1]);
        return res;
    }
};

//time O(m)  space O(mn)
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */