class Solution {
private:
    void dfs(int n, int &cur, vector<int> &res) {
        if (n == 0) {
            res.push_back(cur);
            return;
        }
        dfs(n - 1, cur, res);
        cur ^= (1 << n - 1);
        dfs(n - 1, cur, res);
    }
public:
    vector<int> grayCode(int n) {
        int cur = 0;
        vector<int> res;
        dfs(n, cur, res);
        return res;
    }
};
//recur
// 0 0 0
// 0 0 1
// 0 1 1
// 0 1 0
// 1 1 0
// 1 1 1
// 1 0 1
// 1 0 0