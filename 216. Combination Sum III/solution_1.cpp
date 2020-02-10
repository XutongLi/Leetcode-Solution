class Solution {
private:
    void dfs(int idx, int k, int n, vector<int> &cur, vector<vector<int>> &res) {
        if (k == 0) {   //k个数字
            if (n == 0) //和为n
                res.push_back(cur);
            return;
        }
        for (int i = idx; i <= 9; ++ i) {
            if (i > n)
                break;
            cur.push_back(i);
            dfs(i + 1, k - 1, n - i, cur, res);
            cur.pop_back();
        }
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