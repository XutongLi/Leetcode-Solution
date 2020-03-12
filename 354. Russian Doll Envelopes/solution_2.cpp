class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int binarySearch(vector<int> &dp, int l, int r, int val) {
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (dp[m] > val)
                r = m - 1;
            else if (dp[m] < val)
                l = m + 1;
            else
                return m;
        }
        return l;
    }
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        if (n == 0)
            return 0;
        sort(env.begin(), env.end(), cmp);
        vector<int> dp;
        dp.push_back(env[0][1]);
        for (int i = 1; i < n; ++ i) {
            if(env[i][1] > dp[dp.size() - 1])
                dp.push_back(env[i][1]);
            else
                dp[binarySearch(dp, 0, dp.size() - 1, env[i][1])] = env[i][1];
        }
        return dp.size();
    }
};
//dp + binary search
//time O(nlogn) space O(n)
//width上排序，width相同时，按照height递减排序
//height上使用 longest increasing subsequence 