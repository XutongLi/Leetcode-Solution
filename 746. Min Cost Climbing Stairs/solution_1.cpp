class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if (len == 0)   return 0;
        if (len == 1)   return cost[0];
        if (len == 2)   return min(cost[0], cost[1]);
        for (int i = 2; i < len; i ++) 
            cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
        return min(cost[len - 1], cost[len - 2]);
    }
};