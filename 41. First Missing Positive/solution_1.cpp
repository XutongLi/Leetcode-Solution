class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), idx = 0;
        while (idx < n) {
            if (nums[idx] != idx + 1) {
                if (nums[idx] > 0 && nums[idx] <= n && nums[idx] != nums[nums[idx] - 1]) {
                    swap(nums[idx], nums[nums[idx] - 1]);
                }
                else 
                    ++ idx;
            }
            else
                ++ idx;
        }
        for (int i = 0; i < n; ++ i) {
            if (i + 1 != nums[i])
                return i + 1;
        }
        return n + 1;
    }
};
//3 4 -1 1
//-1 4 3 1
//-1 1 3 4
//1 -1 3 4
//返回2