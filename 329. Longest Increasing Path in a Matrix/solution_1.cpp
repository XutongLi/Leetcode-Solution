class Solution {
private:
    void dfs(const vector<vector<int>> &arr, int i, int j, vector<vector<int>> &mem) {
        mem[i][j] = 1;
        for (int h = -1; h <= 1; ++ h) {
            for (int v = -1; v <= 1; ++ v) {
                if (h != 0 && v != 0 || h == 0 && v == 0)
                    continue;
                int x = i + h, y = j + v;
                if (x < 0 || x >= arr.size() || y < 0 || y >= arr[0].size() || arr[x][y] <= arr[i][j])
                    continue;
                if (mem[x][y] == 0)
                    dfs(arr, x, y, mem);
                mem[i][j] = max(mem[i][j], mem[x][y] + 1);
            }
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> mem(m, vector<int>(n, 0));  //mem[i][j]为从matrix[i][j]开始的最大长度
        int maxi = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (mem[i][j] > 0)
                    continue;
                dfs(matrix, i, j, mem);
                maxi = max(maxi, mem[i][j]);
            }
        }
        return maxi;
    }
};