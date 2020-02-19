class Solution {
private:
    void dfs(int n, int num, unordered_set<int> &visited, vector<int> &res) {
        visited.insert(num);
        res.push_back(num);
        for (int i = 0; i < n; ++ i) {
            int tmp = num;
            num ^= (1 << i);
            if (visited.find(num) == visited.end()) {
                dfs(n, num, visited, res);
                return;     //找到一个相邻数字即可
            }
            num = tmp;
        }
    }
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        unordered_set<int> visited;
        dfs(n, 0, visited, res);
        return res;
    }
};
//dfs + bit manipulation