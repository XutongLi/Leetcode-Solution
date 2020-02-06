class Solution {
private:
    pair<int, int> nextIdx(int i, int j) {  //求出当前坐标的下一个坐标
        int x = (i * 9 + j + 1) / 9;
        int y = (i * 9 + j + 1) % 9;
        return make_pair(x, y);
    }
    bool dfs(vector<vector<char>> &m, int i, int j, vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &square) {
        int x = nextIdx(i, j).first, y = nextIdx(i, j).second;
        if (m[i][j] != '.') { //该位置已有数字
            if (i == 8 && j == 8)
                return true;
            return dfs(m, x, y, row, col, square); 
        }
        //该位置没有数字
        for (int n = 0; n < 9; ++ n) {
            if (row[i][n] || col[j][n] || square[(i / 3) * 3 + j / 3][n])   //此数字已重复
                continue;
            m[i][j] = n + 1 + '0';
            if (i == 8 && j == 8)
                return true;
            row[i][n] = true;
            col[j][n] = true;
            square[(i / 3) * 3 + j / 3][n] = true;
            if (dfs(m, x, y, row, col, square))
                return true;
            m[i][j] = '.';      //此数字未成功则回溯，用下一个数字
            row[i][n] = false;
            col[j][n] = false;
            square[(i / 3) * 3 + j / 3][n] = false;
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& m) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> square(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++ i) {
            for (int j = 0; j < 9; ++ j) {
                if (m[i][j] == '.')
                    continue;
                int num = m[i][j] - '1';
                row[i][num] = true;
                col[j][num] = true;
                square[(i / 3) * 3 + j / 3][num] = true;
            }
        }
        dfs(m, 0, 0, row, col, square);
    }
};
//backtracking