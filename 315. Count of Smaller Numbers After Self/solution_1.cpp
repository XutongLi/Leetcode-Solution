class Solution {
private:
    using iter = vector<pair<int, int>>::iterator;
    void mergeSort(iter l, iter r, vector<int> &cnt) {
        if (r - l <= 1)
            return;
        iter m = l + (r - l) / 2;
        mergeSort(l, m, cnt);
        mergeSort(m, r, cnt);
        for (iter i = l, j = m; i < m; ++ i) {
            while (j < r && (*i).first > (*j).first)
                ++ j;
            cnt[(*i).second] += j - m;
        }
        inplace_merge(l, m, r);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> cnt(nums.size());
        if (nums.empty())
            return cnt;
        int n = nums.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++ i) {
            vec.push_back(make_pair(nums[i], i));
        }
        mergeSort(vec.begin(), vec.end(), cnt);
        return cnt;
    }
};
//merge sort O(nlogn)
//在一个数右边较小的数，是进行（从小到大）排序时从该数右边到达左边的数，可用merge sort解决
//merge时对于左半部分一个数，右半部分比它小的数会移动至该数左边
//5261738
//以5为例，merge 5 26，得2， merge 256 1378，的1和3，所以5右边小的数量为3
//inplace_merge(l, m, r) merges [l, m) and [m, r)
//https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/138154/The-C%2B%2B-merge-sort-template-for-pairs-'i'-'j'-problem
