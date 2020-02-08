class Solution {
private:
    void dfs(int y, int n, vector<bool> &ver, vector<bool> &lt2rb, vector<bool> &rt2lb, vector<string> &cur, vector<vector<string>> &res) {
        if (y == n + 1) {
            res.push_back(cur);
            return;
        }
        for (int x = 1; x <= n; ++ x) {
            if (ver[x] || lt2rb[x + y - 1] || rt2lb[n - x + y])
                continue;
            ver[x] = true;
            lt2rb[x + y - 1] = true;
            rt2lb[n - x + y] = true;
            cur.push_back(string(x - 1, '.') + "Q" + string(n - x, '.'));
            dfs(y + 1, n, ver, lt2rb, rt2lb, cur, res);
            cur.pop_back();
            ver[x] = false;
            lt2rb[x + y - 1] = false;
            rt2lb[n - x + y] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0)
            return vector<vector<string>>();
        vector<vector<string>> res;
        vector<string> cur;
        vector<bool> ver(n + 1, false); //存储垂直方向已被占的列
        vector<bool> lt2rb(2 * n, false);   //存储左上到右下方向已被占的列
        vector<bool> rt2lb(2 * n, false);   //存储右上到左下方向已被占的列
        dfs(1, n, ver, lt2rb, rt2lb, cur, res);
        return res;
    }
};
//backtracking
//设原点在左下角，等同于坐标系