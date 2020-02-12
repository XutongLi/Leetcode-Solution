class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.empty())
            return res;
        
        int k = 3, len = nums.size();
        vector<int> ele(k - 1, nums[0]);
        vector<int> cnt(k - 1, 0);
        for (int i = 0; i < len; ++ i) {
            bool equal = false;
            for (int j = 0; j < k - 1 && !equal; ++ j) {
                if (ele[j] == nums[i]) {
                    ++ cnt[j];
                    equal = true;
                }
            }
            if (equal)
                continue;
            bool zero = false;
            for (int j = 0; j < k - 1 && !zero; ++ j) {
                if (cnt[j] == 0) {
                    ele[j] = nums[i];
                    cnt[j] = 1;
                    zero = true;
                }
            }
            if (zero)
                continue;
            for (int j = 0; j < k - 1; ++ j)
                -- cnt[j];
        }
        
        cnt.assign(k - 1, 0);
        for (auto n : nums) {
            for (int j = 0; j < k - 1; ++ j) {
                if (ele[j] == n) {
                    ++ cnt[j];
                    break;
                }
            }
        }
        
        for (int j = 0; j < k - 1; ++ j)
            if (cnt[j] > len / k)
                res.push_back(ele[j]);
        return res;
    }
};
//time O(kn), space O(k)
//Boyer-Moore Majority Vote algorithm
//将问题扩展到k majority