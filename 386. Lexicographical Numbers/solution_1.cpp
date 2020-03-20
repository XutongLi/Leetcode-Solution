class Solution {
private:
    void dfs(int num, int n, vector<int> &res) {
        for (int k = 0; k <= 9; ++ k) {
            if (k > n)  
                return;
            int cur = num * 10 + k;
            if (cur > n)
                continue;
            if (cur != 0) {
                res.push_back(cur);
                dfs(cur, n, res);
            }
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        dfs(0, n, res);
        return res;
    }
};
//dfs