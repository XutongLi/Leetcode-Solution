class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        map<int, bool> mp;
        permute(nums, 0, mp, cur, res);
        return res;
    }
    void permute(const vector<int> &nums, int idx, map<int, bool> &mp, vector<int> &cur, vector<vector<int>> & res) {
        if (idx == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int n : nums) {
            if (mp[n])
                continue;
            cur.push_back(n);
            mp[n] = true;
            permute(nums, idx + 1, mp, cur, res);
            mp[n] = false;
            cur.pop_back();
        }
    }
};