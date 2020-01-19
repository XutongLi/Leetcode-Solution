class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> pre;    //<sub_sum, subsum occurrence numbers> 
        pre[0] = 1; //when nums[i] == k, let res += 1
        for (int i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
            res += pre[sum - k];
            ++ pre[sum];
        }
        return res;
    }
};
//O(n)
//prefix sum