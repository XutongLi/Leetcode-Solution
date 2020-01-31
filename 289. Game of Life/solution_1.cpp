class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty())
            return;
        //-1下一代死亡, 2下一代复活
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int live = 0;
                for (int h = -1; h <= 1; ++ h) {
                    for (int v = -1; v <= 1; ++ v) {
                        if (h == 0 && v == 0)
                            continue;
                        int x = i + h, y = j + v;
                        if (x < 0 || x >= m || y < 0 || y >= n) 
                            continue;
                        if (board[x][y] == 1 || board[x][y] == -1) 
                            ++ live;
                    }
                }
                if (board[i][j] == 0 && live == 3) 
                    board[i][j] = 2;
                if (board[i][j] == 1 && (live < 2 || live > 3))
                    board[i][j] = -1;
            }
        }
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }    
    }
};