class Solution {
private:
    void dfs(int idx, int m, vector<int> &nums, vector<vector<int>> &mem, int &res) {
        if (m == 1) {
            mem[idx][m] = accumulate(nums.begin() + idx, nums.end(), 0);
            return;
        }
        int sum = 0, cur_min_maxi = INT_MAX;
        for (int i = idx; i <= nums.size() - m; ++ i) {
            sum += nums[i];
            if (mem[i + 1][m - 1] == -1)
                dfs(i + 1, m - 1, nums, mem, res);
            cur_min_maxi = min(cur_min_maxi, max(sum, mem[i + 1][m - 1]));
        }
        mem[idx][m] = cur_min_maxi;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int res = INT_MAX;
        vector<vector<int>> mem(nums.size() + 1, vector<int>(m + 1, -1));
        dfs(0, m, nums, mem, res);
        return mem[0][m];
    }
};
//dfs with memoization(DP)
//mem[i][j] 表示从nums的i开始，还有j个子数组的条件下，最小的子数组最大值