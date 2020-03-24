class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int mini = INT_MAX;
        long sum = 0;
        for (int n : nums) {
            mini = min(mini, n);
            sum += n;
        }
        return sum - mini * nums.size();
    }
};
//time O(n)  space O(1)
//将n-1个元素加1，相当于将一个元素减1，再将所有元素加1，所以只考虑何元素减1
//要令所有元素相等，即使得每个元素都减到和最小元素相等