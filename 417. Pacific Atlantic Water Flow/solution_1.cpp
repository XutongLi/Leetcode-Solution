class Solution {
private:
    void dfs(const vector<vector<int>>& arr, int i, int j, vector<vector<vector<bool>>> &mem, int m, int n, int flag) {
        mem[flag][i][j] = true;
        for (int h = -1; h <= 1; ++ h) {
            for (int v = -1; v <= 1; ++ v) {
                if (h == 0 && v == 0 || h != 0 && v != 0)
                    continue;
                int x = i + h, y = j + v;
                if (x < 0 || x >= m || y < 0 || y >= n || arr[x][y] < arr[i][j] || mem[flag][x][y])
                    continue;
                dfs(arr, x, y, mem, m, n, flag);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0;
        vector<vector<int>> res;
        if (m == 0 || n == 0)
            return res;
        vector<vector<vector<bool>>> mem(2, vector<vector<bool>>(m, vector<bool>(n, false)));  //0 - Pac  1 - Atl
        
        //从边缘开始，沿着非递减路径对Pac和Atl分别标记mem
        for(int i = 0; i < m; ++ i) {
            if (!mem[0][i][0])  
                dfs(matrix, i, 0, mem, m, n, 0);
            if (!mem[1][i][n - 1])  
                dfs(matrix, i, n - 1, mem, m, n, 1);
        }
        for (int j = 0; j < n; ++ j) {
            if (!mem[0][0][j])
                dfs(matrix, 0, j, mem, m, n, 0);
            if (!mem[1][m - 1][j])
                dfs(matrix, m - 1, j, mem, m, n, 1);
        }
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (mem[0][i][j] && mem[1][i][j])
                    res.push_back(vector<int>{i, j});
            }
        }
        return res;
    }
};
//DFS with Memoization
//time O(mn) space O(mn)