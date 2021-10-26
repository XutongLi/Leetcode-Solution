class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long, int>> mp(nums.size());
        int res = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            for (int j = 0; j < i; ++ j) {
                long d = (long)nums[i] - (long)nums[j];
                res += mp[j][d];
                mp[i][d] += mp[j][d] + 1;
            }
        }
        return res;
    }
};
// O(n^2)