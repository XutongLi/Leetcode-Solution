class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> hvec(9, vector<bool>(9, false));
        vector<vector<bool>> vvec(9, vector<bool>(9, false));
        vector<vector<bool>> svec(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++ i) {
            for (int j = 0; j < 9; ++ j) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0' - 1;
                int idx = (i / 3) * 3 + (j / 3);
                if (hvec[i][num] || vvec[j][num] || svec[idx][num])
                    return false;
                hvec[i][num] = true;
                vvec[j][num] = true;
                svec[idx][num] = true;
            }
        }
        return true;
    }
};