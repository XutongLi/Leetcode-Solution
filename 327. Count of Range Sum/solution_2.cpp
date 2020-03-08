class Solution {
private:
    int mergeSort(vector<long> &sums, int lo, int up, int st, int end) {
        if (end - st <= 1)  //单个元素
            return 0;
        int mid = (end - st) / 2 + st;
        int cnt = mergeSort(sums, lo, up, st, mid) + mergeSort(sums, lo, up, mid, end); //此步分治后，左右部分已有序
        int l = mid, r = mid;
        for (int i = st; i < mid; ++ i) {
            while (l < end && sums[l] - sums[i] < lo)   ++ l;   //计算右半部分针对左半部分差值满足条件的数量
            while (r < end && sums[r] - sums[i] <= up)  ++ r;
            cnt += r - l;
        }
        inplace_merge(sums.begin() + st, sums.begin() + mid, sums.begin() + end);
        return cnt;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        vector<long> sums(len + 1, 0);
        for (int i = 0; i < len; ++ i)
            sums[i + 1] = nums[i] + sums[i];    //sums[0]恰好表示无元素之前的和，sums[i] - sums[0]表示nums[0]+...+nums[i-1]
        return mergeSort(sums, lower, upper, 0, len + 1);
    }
};
//mergeSort time O(nlogn) space O(n)
//https://leetcode.com/problems/count-of-range-sum/discuss/77990/Share-my-solution
//本解法的范围表示一律为[i,j)