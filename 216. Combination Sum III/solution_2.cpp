class Solution {
private:
    void dfs(int idx, int k, int n, vector<int> &cur, vector<vector<int>> &res) {
        if (k == 0) {   //k个数字
            if (n == 0) //和为n
                res.push_back(cur);
            return;
        }
        if (idx > n || idx > 9)
            return;
        cur.push_back(idx);
        dfs(idx + 1, k - 1, n - idx, cur, res);
        cur.pop_back();
        dfs(idx + 1, k, n, cur, res);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k <= 0 || n < k * (k + 1) / 2 || n > (19 - k) * k / 2)  
            return res;
        vector<int> cur;
        dfs(1, k, n, cur, res);
        return res;
    }
};
//一个组合中数字不能重复，如不能 111
//非循环式backtracking