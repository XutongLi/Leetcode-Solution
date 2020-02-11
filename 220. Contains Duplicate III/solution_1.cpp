class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window;
        for (int i = 0; i < nums.size(); ++ i) {
            long long num = nums[i];
            if (i > k)
                window.erase(nums[i - k - 1]);
            for (auto it = window.lower_bound(num - t); it != window.end(); ++ it) {
                if (*it - num <= t) 
                    return true;
                else
                    break;
            }
            window.insert(num);
        }
        return false;
    }
};
//sliding window