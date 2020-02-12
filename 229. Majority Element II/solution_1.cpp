class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.empty())
            return res;
        
        int num1 = nums[0], num2 = nums[0], cnt1 = 0, cnt2 = 0, len = nums.size();
        for (int i = 0; i < len; ++ i) {
            if (nums[i] == num1) 
                ++ cnt1;
            else if (nums[i] == num2)
                ++ cnt2;
            else if (cnt1 == 0) {
                num1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                num2 = nums[i];
                cnt2 = 1;
            }
            else {
                -- cnt1;
                -- cnt2;
            }
        }
        
        cnt1 = cnt2 = 0;
        for (auto n : nums) {
            if (n == num1)
                ++ cnt1;
            else if (n == num2)
                ++ cnt2;
        }
        
        if (cnt1 > len / 3)
            res.push_back(num1);
        if (cnt2 > len / 3)
            res.push_back(num2);
        return res;
    }
};
//time O(n), space O(1)
//Boyer-Moore Majority Vote algorithm
//数量大于len / 3的数字最多有2个，所以设两个变量num1和num2