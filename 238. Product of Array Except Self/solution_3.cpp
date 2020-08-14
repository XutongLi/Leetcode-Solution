class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return vector<int>();
        vector<int> res(n, 1);
        int left = 1;
        for (int i = 0; i < n - 1; ++ i) {
            left *= nums[i];
            res[i + 1] *= left;
        }
        int right = 1;
        for (int i = n - 1; i > 0; -- i) {
            right *= nums[i];
            res[i - 1] *= right;
        }
        return res;
    }
};