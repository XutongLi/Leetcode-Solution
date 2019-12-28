class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty())
            return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                flag[i][j] = true;
                bool res = exist(board, word, i, j, 0, flag); 
                if (res)
                    return true;
                flag[i][j] = false;
            }
                
        }
        return false;
    }
    bool exist(const vector<vector<char>> &arr, const string &word, int i, int j, int idx, vector<vector<bool>> &flag) {
        if (arr[i][j] != word[idx])
            return false;
        else if (idx == word.size() - 1)
            return true;
        for (int k = -1; k <= 1; ++ k) {
            for (int v = -1; v <= 1; ++ v) {
                if (k != 0 && v != 0)
                    continue;
                int x = i + k, y = j + v;
                if (x >= 0 && x < arr.size() && y >= 0 && y < arr[0].size() && !flag[x][y]) {
                    flag[x][y] = true;
                    bool res =  exist(arr, word, x, y, idx + 1, flag);
                    if (res)
                        return true;
                    flag[x][y] = false;
                }
            }
        }
        return false;
    }
};