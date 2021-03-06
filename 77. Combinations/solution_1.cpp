class Solution {
private:
    void dfs(int idx, int n, int k, vector<int> &cur, vector<vector<int>> &res) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = idx; i <= n - k + 1; ++ i) {
            cur.push_back(i);
            dfs(i + 1, n, k - 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n <= 0)
            return res;
        vector<int> cur;
        dfs(1, n, k, cur, res);
        return res;
    }
};
//backtracking