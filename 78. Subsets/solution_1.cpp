class Solution {
private:
    void backtrack(vector<int> &nums, int idx, vector<int> &cur, vector<vector<int>> &res) {
        res.push_back(cur);
        for (int i = idx;i < nums.size(); ++ i) {
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(nums, 0, cur, res);
        return res;
    }
};