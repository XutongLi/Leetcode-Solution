class Solution {
private:
    //获取nums k个元素的最大子数组
    vector<int> vecKMax(const vector<int> &nums, int k) {
        int drop = nums.size() - k;  //可丢弃的元素数量
        vector<int> ret;
        for (int num : nums) {
            while (drop > 0 && !ret.empty() && num > ret.back()) {
                -- drop;
                ret.pop_back();
            }
            ret.push_back(num);
        }
        ret.resize(k);
        return ret;
    }
    //merge two vec
    vector<int> mergeVec(const vector<int> &nums1, const vector<int> &nums2) {
        vector<int> ret;
        auto p1 = nums1.begin(), end1 = nums1.end();
        auto p2 = nums2.begin(), end2 = nums2.end();
        while (p1 != end1 || p2 != end2)
            //比较时必须对两个数组的子数组进行字典序比较，不能只比较单个元素
            ret.push_back(lexicographical_compare(p1, end1, p2, end2) ? *p2 ++ : *p1 ++);
        return ret;
        
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res;
        for (int i = 0; i <= k; ++ i) {
            if (i <= n1 && k - i <= n2)
                res = max(res, mergeVec(vecKMax(nums1, i), vecKMax(nums2, k - i))); //给nums1、nums2分配所有可能长度
        }
        return res;
    }
};
//divide and conquer    time O(kn)