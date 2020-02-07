class Solution {
private:
    void track(const vector<int> &nums, int idx, unordered_map<int, int> &mp, vector<int> &cur, vector<vector<int>> &res) {
        if (idx == nums.size()) {
            res.push_back(cur);
            return;
        }
        int pre = INT_MIN;
        for (auto n : nums) {
            if (mp[n] == 0)
                continue;
            if (pre == INT_MIN)     //初始化pre
                pre = n;
            else if (n == pre)      //下一个idx不放入相同数字
                continue;
            pre = n;
            cur.push_back(n);
            -- mp[n];
            track(nums, idx + 1, mp, cur, res);
            ++ mp[n];
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (auto n : nums)
            ++ mp[n];
        vector<int> cur;
        track(nums, 0, mp, cur, res);
        return res;
    }
};
//backtracking