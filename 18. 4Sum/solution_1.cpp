class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; ++ i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;  //border
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            for (int j = i + 1; j < n - 2; ++ j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;  //border
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back(vector<int>{ nums[i], nums[j], nums[l], nums[r] });
                        while (l < n - 1 && nums[l + 1] == nums[l])
                            ++ l;
                        while (r > 0 && nums[r - 1] == nums[r])
                            -- r;
                        ++ l;   -- r;   
                    }
                    else if (sum > target)
                        -- r;
                    else
                        ++ l;
                }
            }
        }
        return res;
    }
};
//time O(n^3)
//two pointers