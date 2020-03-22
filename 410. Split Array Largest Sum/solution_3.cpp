class Solution {
private:
    //判断是否能将一个数组分为n个子数组，且每个子数组之和不大于maxi
    bool canSplit(const vector<int> &nums, int n, int maxi) {
        long sum = 0;
        for (int num : nums) {
            if (num > maxi) return false;
            else if (num + sum <= maxi) sum += num;
            else {  //num + sum > maxi
                -- n;
                if (n == 0) return false;
                sum = num;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        long left = 0, right = 0;   //left为nums中最大元素，right为sum(nums)
        for (long num : nums) {
            left = max(left, num);  
            right += num;
        }
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (canSplit(nums, m, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
//binary Search 
//time O(nlogm) m为sum(nums)  space O(n)
//https://leetcode.com/problems/split-array-largest-sum/discuss/89819/C%2B%2B-Fast-Very-clear-explanation-Clean-Code-Solution-with-Greedy-Algorithm-and-Binary-Search