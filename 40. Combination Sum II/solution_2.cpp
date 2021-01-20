class Solution {
private:
    void dfs(vector<int> &candidates, vector<int> &cur, vector<vector<int>> &res, int target, int sum, int idx) {
        if (sum == target) {
            res.push_back(cur);
            return;
        }
        if (sum > target)   return;
        for (int i = idx; i < candidates.size(); ++ i) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target) continue;
            cur.push_back(candidates[i]);
            dfs(candidates, cur, res, target, sum + candidates[i], i + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, cur, res, target, 0, 0);
        return res;
    }
};
//另一种方式的backtracking
//solution_1为每次递归放入或不放入candidates的第idx个数
//此方法为每要放入一个数时，对candidates中此数及以后位置的数进行遍历