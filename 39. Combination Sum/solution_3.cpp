class Solution {
private:
    void backtrack(vector<int> &nums, int target, int idx, vector<int> &cur, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = idx; i < nums.size(); ++ i) {
            if (nums[i] > target)
                break;
            cur.push_back(nums[i]);
            backtrack(nums, target - nums[i], i, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(candidates, target, 0, cur, res);
        return res;
    }
};