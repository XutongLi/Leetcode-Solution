class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        if (len == 0)
            return res;
        map<int, int> m;
        for (int i = 0; i < len; i ++) {
            int tmp = target - nums[i];
            if (m.find(tmp) != m.end()) {
                res.push_back(m[tmp]);
                res.push_back(i);
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};