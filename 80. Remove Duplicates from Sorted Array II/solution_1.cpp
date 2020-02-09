class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;
        int flag = 0, idx = 0;
        for (int i = 1; i < n; ++ i) {
            if (nums[i] == nums[i - 1]) {
                ++ flag;
                if (flag < 2)
                    nums[++ idx] = nums[i];
            }
            else {
                nums[++ idx] = nums[i];
                flag = 0;
            }
        }
        return idx + 1;
    }
};