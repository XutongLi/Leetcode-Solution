class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), maxi = INT_MIN;
        for (int j = 0; j < n; ++ j) {
            vector<int> dp(m, 0);
            for (int l = j; l < n; ++ l) {
                for (int i = 0; i < m; ++ i) {
                    dp[i] += matrix[i][l];
                }
                //计算dp最大子数组和，若最大值不超过k则省去下面的二分查找
                int submax = dp[0], cursum = dp[0];
                for (int i = 1; i < m; ++ i) {
                    cursum = cursum < 0 ? dp[i] : cursum + dp[i];
                    submax = max(submax, cursum);
                }
                if (submax <= k) {
                    maxi = max(maxi, submax);
                    continue;
                }
                //最大值超过k，利用set二分查找
                set<int> st;
                st.insert(0);
                int sum = 0;
                for (int i = 0; i < m; ++ i) {
                    sum += dp[i];
                    auto it = st.lower_bound(sum - k); // sum - (*it) <= k   lower_bound二分查找
                    if (it != st.end())
                        maxi = max(maxi, sum - (*it));
                    st.insert(sum);
                }
            }
        }
        return maxi;
    }
};
//dp + binary search
//m 远大于 n  time O(n^2*m*logm)  space O(m)
//find the max sum rectangle in 2D array （O(m*n^2）)的变种 （每一列使用53. Maximum Subarray寻找最大连续和）