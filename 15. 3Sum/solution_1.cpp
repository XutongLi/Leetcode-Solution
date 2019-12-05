class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n == 0)     return res;
        
        sort(nums.begin(), nums.end());
        for (int k = 0; k < n; k ++) {
            if (nums[k] > 0)    continue;
            if (k > 0 && nums[k] == nums[k - 1])    continue;
            
            int var = 0 - nums[k];
            int i = k + 1, j = n - 1;
            while (i < j) {
                if (nums[i] + nums[j] == var) {
                    res.push_back(vector<int>{nums[k], nums[i], nums[j]});
                    while (i < j && nums[i + 1] == nums[i])
                        i ++;
                    while (i < j && nums[j] == nums[j - 1])
                        j --;
                    i ++;   j --;
                }
                else if (nums[i] + nums[j] < var)
                    i ++;
                else
                    j --;
            }
        }
        return res;
    }
}; //o(n^2)