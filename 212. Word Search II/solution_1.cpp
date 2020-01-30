class Solution {
private:
    bool find(vector<vector<char>> &board, const string &w, int i, int j, int idx) {
        if (board[i][j] != w[idx])
            return false;
        if (idx == w.size() - 1)
            return true;
        char tmp = board[i][j];
        board[i][j] = '*';
        for (int h = -1; h <= 1; ++ h) {
            for (int v = -1; v <= 1; ++ v) {
                if (h != 0 && v != 0)
                    continue;
                int x = i + h, y = j + v;
                if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '*')
                    continue;
                if (find(board, w, x, y, idx + 1)) {
                    board[i][j] = tmp;
                    return true;
                }
            }
        }
        board[i][j] = tmp;
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || words.empty())
            return res;
        int m = board.size(), n = board[0].size();
        for (auto w : words) {
            bool exist = false;
            for (int i = 0; i < m && !exist; ++ i) {
                for (int j = 0; j < n && !exist; ++ j) {
                    if (find(board, w, i, j, 0)) {
                        res.push_back(w);
                        exist = true;
                    }
                }
            }
        }
        return res;
    }
};
//DFS Backtracking