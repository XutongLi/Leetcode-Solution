class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return false;
        unordered_set<int> m;
        for (int i = 0; i < len; i ++) {
            if (m.find(nums[i]) != m.end())
                return true;
            m.insert(nums[i]);
        }
        return false;
    }
};