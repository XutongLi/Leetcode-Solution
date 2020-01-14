class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) 
            return 0;
        static vector<int> dp = {0};
        while (dp.size() <= n) {
            int i = dp.size();
            dp.push_back(INT_MAX);
            for (int j = 1; j * j <= i; ++ j)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};
//dp[i] 表示可以组成i的完全平方数字的最小个数
//static vector用于保存已得出的dp中的元素（只针对有多个测试用例的情况有优化）