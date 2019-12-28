class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty())
            return false;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                bool res = exist(board, word, i, j, 0); 
                if (res)
                    return true;
            }
                
        }
        return false;
    }
    bool exist(vector<vector<char>> &arr, const string &word, int i, int j, int idx) {
        if (arr[i][j] != word[idx])
            return false;
        else if (idx == word.size() - 1)
            return true;
        char tmp = arr[i][j];
        arr[i][j] = '*';
        for (int k = -1; k <= 1; ++ k) {
            for (int v = -1; v <= 1; ++ v) {
                if (k != 0 && v != 0)
                    continue;
                int x = i + k, y = j + v;
                if (x >= 0 && x < arr.size() && y >= 0 && y < arr[0].size() && arr[x][y] != '*') {
                    bool res = exist(arr, word, x, y, idx + 1);
                    if (res)
                        return true;
                }
            }
        }
        arr[i][j] = tmp;
        return false;
    }
};//降低空间复杂度、回溯执行位置改变