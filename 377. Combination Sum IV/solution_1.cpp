class Solution {
private:
    int dfs(const vector<int> &nums, int target, unordered_map<int, int> &mem) {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (mem.find(target) != mem.end())
            return mem[target];
        int res = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            res += dfs(nums, target - nums[i], mem);
        }
        mem[target] = res;
        return res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty() || target <= 0)
            return 0;
        unordered_map<int, int> mem;
        return dfs(nums, target, mem);
    }
};
//dfs with memorization