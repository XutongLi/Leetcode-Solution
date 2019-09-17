class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1)
            return 0;
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = 1;
        int res = 0;
        while (lo < len && hi < len) {
            if (nums[hi] - nums[lo] < k)
                hi ++;
            else if (nums[hi] - nums[lo] > k)
                lo ++;
            else {
                res ++;
                while (lo < len - 1 && nums[lo] == nums[lo + 1])
                    lo ++;
                lo ++;
                while (hi < len - 1 && nums[hi] == nums[hi + 1])
                    hi ++;
                hi ++;
            }
            if (hi == lo)
                hi ++;
        }
        return res;
    }
};