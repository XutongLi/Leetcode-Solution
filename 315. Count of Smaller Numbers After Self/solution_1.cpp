class Solution {
private:
	void mergeSort(vector<pair<int, int>> &vec, int l, int r, vector<int> &res) {
        if (r - l <= 1)	return;
        int m = (r - l) / 2 + l;
        mergeSort(vec, l, m, res);
        mergeSort(vec, m, r, res);
        for (int i = l, j = m; i < m; ++ i) {
            while (j < r && vec[j].first < vec[i].first)	++ j;
            res[vec[i].second] += (j - m);
        }
        inplace_merge(vec.begin() + l, vec.begin() + m, vec.begin() + r);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        if (n == 0)	return res;
            vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++ i)
            vec.push_back({nums[i], i});
        mergeSort(vec, 0, n, res);
        return res;
    }
};

//merge sort O(nlogn)
//在一个数右边较小的数，是进行（从小到大）排序时从该数右边到达左边的数，可用merge sort解决
//merge时对于左半部分一个数，右半部分比它小的数会移动至该数左边
//5261738
//以5为例，merge 5 26，得2， merge 256 1378，的1和3，所以5右边小的数量为3
//inplace_merge(l, m, r) merges [l, m) and [m, r)
//https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/138154/The-C%2B%2B-merge-sort-template-for-pairs-'i'-'j'-problem
