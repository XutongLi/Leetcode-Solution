class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int mini = INT_MAX, l = 0,  sum = 0;
        for (int r = 0; r < n; ++ r) {
            sum += nums[r];
            while (sum >= s) {
                mini = min(mini, r - l + 1);
                sum -= nums[l ++];
            }
        }
        return mini == INT_MAX ? 0 : mini; 
    }
};
//two pointers O(n)