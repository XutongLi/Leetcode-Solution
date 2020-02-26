class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        int bucketNum = n - 1, bucketSize = ceil(static_cast<double>(maxi - mini) / bucketNum);
        vector<pair<int, int>> bucket(bucketNum, {INT_MAX, 0}); //<min, max> in every bucket
        for (auto n : nums) {
            if (n == mini || n == maxi)
                continue;
            int idx = (n - mini) / bucketSize;
            bucket[idx].first = min(bucket[idx].first, n);
            bucket[idx].second = max(bucket[idx].second, n);
        }
        int res = 0, preMax = mini;
        for (auto b : bucket) {
            if (b.first == INT_MAX) //skip empty bucket
                continue;   
            res = max(res, b.first - preMax);
            preMax = b.second;
        }
        return max(res, maxi - preMax);
    }
};
//bucket sort （桶排序）
//time O(n) space O(n)
//https://leetcode.wang/leetcode-164-Maximum-Gap.html
//其中为何是除以n-1：计算gap只用左bucket的max和右bucket的min计算，所以nums的min和max不参与计算，所以n-2个数要放入桶中，为了有空桶，需要n-1个桶
//桶之外还有mini和maxi