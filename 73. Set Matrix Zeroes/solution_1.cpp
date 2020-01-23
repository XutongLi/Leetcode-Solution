class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        bool frow = false, fcol = false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if (i == 0)     
                        frow = true;
                    if (j == 0)    
                        fcol = true;
                }
            }
        }
        for (int i = 1; i < m; ++ i) {
            for (int j = 1; j < n; ++ j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        }
        if (frow) 
            for (int j = 0; j < n; ++ j)
                matrix[0][j] = 0;
        if (fcol) 
            for (int i = 0; i < m; ++ i)
                matrix[i][0] = 0;
    }
};
//time O(mn)
//space O(1)
//通过矩阵左边界和上边界记录行列为零的情况