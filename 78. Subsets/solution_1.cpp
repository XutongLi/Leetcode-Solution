class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        subsets(nums, res, cur, -1);
        return res;
    }
    void subsets(const vector<int> &nums, vector<vector<int>> &res, vector<int> &cur, const int &n) {
        res.push_back(cur);
        if (n == nums.size() - 1)
            return;
        for (int i = n + 1; i < nums.size(); ++ i) {
            cur.push_back(nums[i]);
            subsets(nums, res, cur, i);
            cur.pop_back();
        }
    }
};