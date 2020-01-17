class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        for (int n = 1; n <= num; ++ n) {
            dp[n] = 1 + dp[n & (n - 1)];
        }
        return dp;
    }
};
/*
计算一个数二级制1的个数代码
while (n) {
    n = n & (n - 1);    //此步可复用
    ++ cnt; 
}
*/