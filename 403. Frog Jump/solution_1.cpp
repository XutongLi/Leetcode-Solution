class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<unordered_set<int>> dp(len);
        if (stones[1] >= 2)
            return false;   //题目描述第一步必为1
        dp[1].insert(1);
        for (int i = 2; i < len; ++ i) {
            for (int j = 1; j < i; ++ j) {
                int dis = stones[i] - stones[j];
                if (dis > len || dp[j].empty())
                    continue;
                if (dp[j].find(dis) != dp[j].end() || dp[j].find(dis + 1) != dp[j].end() 
                    || dp[j].find(dis - 1) != dp[j].end()) {
                    dp[i].insert(dis);
                }
            }
        }
        return !dp[len - 1].empty();
    }
};
//dynamic programming
//time O(n^2) 
//dp[i]为从stones[i]之前某一块石头可以到达stones[i]的步数
//800ms