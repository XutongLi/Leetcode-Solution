class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)   return 0;
        vector<int> dp(len);
        dp[0] = nums[0];
        int res = 0;
        for (int i = 1; i < len; i ++) {
            if (nums[i] < dp[0])
                dp[0] = nums[i];
            else if (nums[i] > dp[res])
                dp[++res] = nums[i];
            else
                dp[binarySearch(dp, 0, res, nums[i])] = nums[i];
        }
        return res + 1;
    }
    int binarySearch(vector<int> dp, int lo, int hi, int key) {
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (dp[mid] == key)
                return mid;
            else if (dp[mid] > key)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;
    }
};