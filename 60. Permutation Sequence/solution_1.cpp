class Solution {
private:
    bool dfs(int idx, int n, int &k, string &res, vector<bool> &visited) {
        if (idx == n) {
            if (-- k == 0)
                return true;
            else
                return false;
        }
        for (int i = 1; i <= n; ++ i) {
            if (visited[i])
                continue;
            visited[i] = true;
            res.push_back(i + '0');
            if (dfs(idx + 1, n, k, res, visited))
                return true;
            res.pop_back();
            visited[i] = false;
        }
        return false;
    }
public:
    string getPermutation(int n, int k) {
        string res = "";
        vector<bool> visited(n + 1, false);
        dfs(0, n, k, res, visited);
        return res;
    }
};
//backtracking