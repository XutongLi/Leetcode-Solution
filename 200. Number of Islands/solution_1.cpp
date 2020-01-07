class Solution {
private:
    void findIsland(vector<vector<char>> &grid, int x, int y, int m, int n) {
        grid[x][y] = '2';
        for (int i = -1; i <= 1; ++ i) {
            for (int j = -1; j <= 1; ++ j) {
                if (i == 0 && j == 0 || i != 0 && j != 0)
                    continue;
                int nx = x + i;
                int ny = y + j;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (grid[nx][ny] == '1')
                    findIsland(grid, nx, ny, m, n);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == '1') {
                    findIsland(grid, i, j, m, n);
                    ++ res;
                }
            }
        }
        return res;
    }
};