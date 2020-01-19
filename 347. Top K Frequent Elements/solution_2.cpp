class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto n : nums) {
            ++ mp[n];
        }
        vector<vector<int>> m(nums.size() + 1);
        vector<int> res;
        for (auto p : mp) {
            m[p.second].push_back(p.first);
        }
        for (int i = m.size() - 1; i > 0; -- i) {
            for (auto n : m[i]) {
                res.push_back(n);
                if (res.size() == k)
                    return res;
            }
        }
        return res;
    }
};
//bucket sort O(n)