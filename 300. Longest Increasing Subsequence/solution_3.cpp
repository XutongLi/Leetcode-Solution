class Solution {
private:
    int binarySearch(vector<int> &vec, int num) {
        int lo = 0, hi = vec.size() - 1;
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (vec[mid] == num)
                return mid;
            else if (vec[mid] > num)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return lo;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        for (int i = 0; i < n; ++ i) {
            int idx = binarySearch(vec, nums[i]);
            if (idx < vec.size())
                vec[idx] = nums[i];
            else if (idx >= vec.size())
                vec.push_back(nums[i]);
        }
        return vec.size();
    }
};