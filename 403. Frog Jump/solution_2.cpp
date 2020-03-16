class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<vector<int>> dp(len, vector<int>(len + 1, false));
        dp[0][1] = true;
        for (int i = 1; i < len; ++ i) {
            for (int j = 0; j < i; ++ j) {
                int dis = stones[i] - stones[j];
                if (dis > len || !dp[j][dis])
                    continue;
                dp[i][dis] = true;
                if (dis + 1 <= len) 
                    dp[i][dis + 1] = true;
                if (dis - 1 >= 0)
                    dp[i][dis - 1] = true;
                if (i == len - 1)
                    return true;
            }
        }
        return false;
    }
};
//dynamic programming
//time O(n^2) 
//dp[i][d]表示stones[i]可以网口走d个unit
//120ms