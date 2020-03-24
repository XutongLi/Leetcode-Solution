class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxi = 0, idx = 0;
        vector<int> cnt(n, 0);
        vector<int> connect(n, 0);
        for (int i = nums.size() - 1; i >= 0; -- i) {
            for (int j = i; j < nums.size(); ++ j) {
                if (nums[j] % nums[i] == 0 && cnt[i] < 1 + cnt[j]) {
                    cnt[i] = 1 + cnt[j];
                    connect[i] = j;
                    if (cnt[i] > maxi) {
                        maxi = cnt[i];
                        idx = i;
                    }
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < maxi; ++ i) {
            res.push_back(nums[idx]);
            idx = connect[idx];
        }
        return res;
    }
};
//DP  time O(n^2) space O(n)
//cnt[i]为 the length of the largest divisible subset whose smallest number is nums[i]
//connect(i)为i所在divisible subset中的下一个idx
//cnt[i] = max(cnt[j] + 1 if nums[j] % nums[i] == 0) j >= i
//因为排好序后，nums[left] % nums[right] != 0，所以判断nums[right] % nums[left] == 0即可