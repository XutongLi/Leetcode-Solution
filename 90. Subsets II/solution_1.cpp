class Solution {
private:
    void dfs(const vector<int> &nums, int idx, vector<int> &cur, vector<vector<int>> &res) {
        res.push_back(cur);
        if (idx == nums.size())
            return;
        for (int i = idx; i < nums.size(); ++ i) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, cur, res);
        return res;
    }
};