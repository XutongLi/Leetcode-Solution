class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end(), greater<int>());
        int n = nums.size();
        for (int i = 0; i < n / 2; ++ i)
            nums[i * 2 + 1] = tmp[i];
        for (int i = n / 2; i < n; ++ i)
            nums[(i - n / 2) * 2] = tmp[i];
    }
};
//time O(nlogn) space O(n) 
//5 4 3 2 1 0
//2 5 1 4 0 3 