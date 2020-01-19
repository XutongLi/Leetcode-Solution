class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<string, int> mp;
        return helper(nums, S, 0, 0, mp);
    }
    int helper(const vector<int> &nums, int S, int idx, int sum, unordered_map<string, int> &mp) {
        string key = to_string(idx) + "-" + to_string(sum);
        if (mp.find(key) != mp.end())
            return mp[key];
        if (idx == nums.size()) {
            if (sum == S)
                return 1;
            else
                return 0;
        }
        int add = helper(nums, S, idx + 1, sum + nums[idx], mp);
        int minus = helper(nums, S, idx + 1, sum - nums[idx], mp);
        mp[key] = add + minus;
        return mp[key];
    }
};
//DFS with memorization
//O(nl) n为nums.size，l为S的可能存在范围（此题为1000）
//将到达某idx的sum值保存，防止计算重叠