class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> border(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (!border[i][j] && (i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O')
                    DFS(board, border, i, j, m, n);
            }
        }
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (!border[i][j])
                    board[i][j] = 'X';
            }
        }
    }
    void DFS(const vector<vector<char>> &board, vector<vector<bool>> &border, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || border[i][j])
            return;
        if (board[i][j] == 'O')
            border[i][j] = true;
        else
            return;
        DFS(board, border, i - 1, j, m, n);
        DFS(board, border, i + 1, j, m, n);
        DFS(board, border, i, j - 1, m, n);
        DFS(board, border, i, j + 1, m, n);
    }
};