class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        for (int i = 0; i < candidates.size(); ++ i) {
            combinationSum(candidates, target, i, vector<int>{}, res);
        }
        return res;
    }
    void combinationSum(const vector<int> &arr, int target, int idx, vector<int> cur, vector<vector<int>> &res) {
        if (arr[idx] == target) {
            cur.push_back(arr[idx]);
            res.push_back(cur);
            return;
        }
        if (target - arr[idx] < 0)
            return;
        cur.push_back(arr[idx]);
        for (int i = idx; i < arr.size(); ++ i) {
            combinationSum(arr, target - arr[idx], i, cur, res);
        }
    }
};