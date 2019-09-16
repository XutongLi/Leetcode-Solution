class Solution {
public:
    int uniquePaths(int m, int n) {
        //int path[m][n];
        int** path = new int*[m];
        for (int i = 0; i < m; i ++)
            path[i] = new int[n];
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                path[i][j] = 1;
                if (i >= 1 && j >= 1)
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
        return path[m - 1][n - 1];
    }
};