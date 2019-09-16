class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1)
            return false;
        map<int, int> m;
        for (int i = 0; i < len; i ++) {
            if (m.find(nums[i]) != m.end()) {
                int cnt = m[nums[i]];
                if (i - cnt <= k)
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};