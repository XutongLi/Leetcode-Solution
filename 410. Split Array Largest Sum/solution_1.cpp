class Solution {
private:
    void dfs(vector<int> &sums, vector<vector<int>> &mem, int m, int idx) {
        if (m == 1) {
            mem[idx][m] = sums[sums.size() - 1] - sums[idx - 1];
            return;
        }
        int cur_min = INT_MAX;
        for (int i = idx; i <= sums.size() - m; ++ i) {
            int sum = sums[i] - sums[idx - 1];
            if (mem[i + 1][m - 1] == -1)
                dfs(sums, mem, m - 1, i + 1);
            cur_min = min(cur_min, max(sum, mem[i + 1][m - 1]));
        }
        mem[idx][m] = cur_min;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        vector<vector<int>> mem(len + 1, vector<int>(m + 1, -1));
        vector<int> sums(len + 1, 0);
        for (int i = 0; i < len; ++ i)
            sums[i + 1] = sums[i] + nums[i];
        dfs(sums, mem, m, 1);
        return mem[1][m];
    }
};
//dfs with memoization(DP)
//mem[i][j] 表示从nums的i开始，还有j个子数组的条件下，最小的子数组最大值