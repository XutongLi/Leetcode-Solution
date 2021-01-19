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
//sum[j] - sum[i] <= k -> sum[i] >= sum[j] - k where j > i 
//find the max sum rectangle in 2D array （O(m*n^2）)的变种 （每一列使用53. Maximum Subarray寻找最大连续和）