class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c || m == 1 && n == 1) {
            return nums;
        }
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                int index = i * c + j;
                res[i][j] = nums[index / n][index % n];
            }
        }
        return res;
    }
};