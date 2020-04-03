class Solution {
private:
    void dfs(int idx, vector<vector<int>>& M, vector<bool> &visited) {
        visited[idx] = true;
        for (int i = 0; i < M.size(); ++ i) {
            if (M[idx][i] == 1 && !visited[i])
                dfs(i, M, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < M.size(); ++ i) {
            if (!visited[i]) {
                ++ res;    
                dfs(i, M, visited);
            }
        }
        return res;
    }
};
//DFS