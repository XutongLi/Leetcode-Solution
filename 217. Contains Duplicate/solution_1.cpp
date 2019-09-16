class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return false;
        map<int, int> m;
        for (int i = 0; i < len; i ++) {
            if (m.find(nums[i]) != m.end())
                return true;
            m[nums[i]] = 1;
        }
        return false;
    }
};