class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0] >= s ? 1 : 0;
        int l = 0, r = l + 1, sum = nums[l] + nums[r], mini = INT_MAX;
        while (true) {
            if (nums[l] >= s || nums[r] >= s)
                return 1;
            else if (sum < s) {
                if (r < n - 1)
                    sum += nums[++ r];
                else
                    break;
            }
            else if (sum >= s) {
                mini = min(mini, r - l + 1);
                if (r == l) {
                    if (r < n - 1) {
                        ++ r;
                        ++ l;
                        sum = nums[r];
                    }
                    else
                        break;
                }
                else {
                    sum -= nums[l ++];
                }
            }
        }
        return mini == INT_MAX ? 0 : mini;
    }
};
//two pointers O(n)