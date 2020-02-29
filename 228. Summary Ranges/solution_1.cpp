class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0)
            return res;
        string cur = to_string(nums[0]);
        bool hasOne = true;
        for (int i = 1; i < n; ++ i) {
            if (nums[i] > 1 + nums[i - 1]) {
                if (!hasOne)
                    cur += "->" + to_string(nums[i - 1]);
                res.push_back(cur);
                cur = to_string(nums[i]);
                hasOne = true;
            }
            else
                hasOne = false;
        }
        if (!hasOne)
            cur += "->" + to_string(nums[n - 1]);
        res.push_back(cur);
        return res;
    }
};
//time O(n) space O(1)