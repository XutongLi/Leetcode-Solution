class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0)
            return 0;
        vector<int> cnt(n + 1, 0);      //引用的计数数组
        for (auto c : citations) {      //桶排序，按照引用数量排序
            if (c >= n)
                ++ cnt[n];
            else
                ++ cnt[c];
        }
        int res = 0;
        for (int i = n; i >= 0; -- i) {
            res += cnt[i];
            if (res >= i)
                return i;
        }
        return 0;
    }
};
//bucket sort
//time O(n)  space O(n)