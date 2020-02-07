class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;    //3456012
            if (nums[m] > nums[m + 1])
                return nums[m + 1];
            else if (nums[m] > nums[r]) //1234560
                l = m + 1;
            else if (nums[m] < nums[l]) //6012345
                r = m;  //nums[m]可能为结果
            else
                return nums[l];     //0123456
        }
        return 0;
    }
};
//binary search
//O(logn)