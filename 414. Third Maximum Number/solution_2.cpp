class Solution {
public:
    int thirdMax(vector<int>& num) {
        vector<int> nums;
        for (int n : num) {
            vector<int>::iterator iter = find(nums.begin(), nums.end(), n);
            if (iter == nums.end())
                nums.push_back(n);
        }
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        for (int n : nums) {
            if (n == max1 || n == max2 || n == max3)
                continue;
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            else if (n > max2) {
                max3 = max2;
                max2 = n;
            }
            else if (n > max3)
                max3 = n;
        }
        return nums.size() >= 3 ? max3 : max1;
    }
};