class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> mp;
        for (int n : nums1)
            mp[n] = false;
        vector<int> res;
        for (int n : nums2) {
            if (mp.find(n) != mp.end() && !mp[n]) {
                res.push_back(n);
                mp[n] = true;
            }
        }
        return res;
    }
};
