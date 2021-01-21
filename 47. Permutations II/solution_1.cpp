class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>> &res, vector<int> &cur, unordered_map<int, int> &mp, int cnt) {
        if (cnt == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++ i) {
            if (mp[nums[i]] == 0)
                continue;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            cur.push_back(nums[i]);
            -- mp[nums[i]];
            dfs(nums, res, cur, mp, cnt + 1);
            ++ mp[nums[i]];
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        unordered_map<int, int> mp;
        for (int n : nums)
            ++ mp[n];
        sort(nums.begin(), nums.end());
        dfs(nums, res, cur, mp, 0);
        return res;
    }
};

//backtracking