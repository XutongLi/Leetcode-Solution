class Solution {
private:
    int dfs(int n, int y, vector<bool> &ver, vector<bool> &lt2rb, vector<bool> &rt2lb) {
        if (y == n + 1) 
            return 1;
        int cnt = 0;
        for (int x = 1; x <= n; ++ x) {
            if (ver[x] || lt2rb[x + y - 1] || rt2lb[n - x + y])
                continue;
            ver[x] = true;
            lt2rb[x + y - 1] = true;
            rt2lb[n - x + y] = true;
            cnt += dfs(n, y + 1, ver, lt2rb, rt2lb);
            ver[x] = false;
            lt2rb[x + y - 1] = false;
            rt2lb[n - x + y] = false;
        }
        return cnt;
    }
public:
    int totalNQueens(int n) {
        if (n <= 1)
            return n;
        vector<bool> ver(n + 1, false);     //存储垂直方向已被占的列
        vector<bool> lt2rb(2 * n, false);   //存储左上到右下方向已被占的列
        vector<bool> rt2lb(2 * n, false);   //存储右上到左下方向已被占的列
        return dfs(n, 1, ver, lt2rb, rt2lb);
    }
};
//backtracking