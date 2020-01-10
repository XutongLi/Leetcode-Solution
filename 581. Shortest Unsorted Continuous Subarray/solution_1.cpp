class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)   return 0;
        int l = 0, r = n - 1;
        
        if (nums[l] > nums[r])
            return r - l + 1;
        
        while (l < n - 1 && nums[l + 1] >= nums[l])
            ++ l;
        if (l == n - 1) 
            return 0;   //sorted
        while (nums[r - 1] <= nums[r])
            -- r;
        
        int maxi = INT_MIN, mini = INT_MAX;
        for (int i = l; i <= r; ++ i) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        
        while (l >= 0 && nums[l] > mini)
            -- l;
        while (r < n && nums[r] < maxi)
            ++ r;
        return r - l - 1;
            
    }
};