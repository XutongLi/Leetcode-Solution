class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int n : nums1)
            mp[n] ++;
        vector<int> res;
        for (int n : nums2) {
            if (mp[n]-- > 0 )
                res.push_back(n);
        }
        return res;
    }
};
