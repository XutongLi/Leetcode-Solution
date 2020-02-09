class Solution {
private:
    void dfs(const vector<int> &arr, int idx, int target, vector<int> &cur, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = idx; i < arr.size(); ++ i) {
            if (arr[i] > target)
                continue;
            if (i > idx && arr[i] == arr[i - 1])    //消除重复
                continue;
            cur.push_back(arr[i]);
            dfs(arr, i + 1, target - arr[i], cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty())
            return res;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(candidates, 0, target, cur, res);
        return res;
    }
};
//另一种方式的backtracking
//solution_1为每次递归放入或不放入candidates的第idx个数
//此方法为每要放入一个数时，对candidates中此数及以后位置的数进行遍历