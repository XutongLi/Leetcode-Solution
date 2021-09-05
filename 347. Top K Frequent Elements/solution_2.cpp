class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        int maxi = 0;
        for (auto n : nums) {
            ++ mp[n];
            maxi = max(maxi, mp[n]);
        }
        vector<vector<int>> cnt(maxi + 1);
        for (auto p : mp)
            cnt[p.second].push_back(p.first);
        for (int i = maxi; i > 0; -- i) {
            for (auto idx : cnt[i]) {
                res.push_back(idx);
                if (res.size() == k)
                    return res;
            }
        }
        return res;
    }
};
//bucket sort O(n)