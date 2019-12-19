class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        combinationSum(candidates, target, 0, cur, res);
        return res;
    }
    void combinationSum(const vector<int> &arr, int target, int idx, vector<int> &cur, vector<vector<int>> &res) {
        //cur不使用引用，运行时间会多出10倍
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (idx == arr.size())
            return;
        if (arr[idx] <= target) {
            cur.push_back(arr[idx]);
            combinationSum(arr, target - arr[idx], idx, cur, res);
            cur.pop_back();
            combinationSum(arr, target, idx + 1, cur, res);
        }
    }
};