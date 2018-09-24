//70%
//reduce space of solution1 from n to 1
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        if (cost == null || cost.length == 0)   return 0;
        if (cost.length == 1)   return cost[0];
        if (cost.length == 2)   return Math.min(cost[0], cost[1]);
        int len = cost.length;
        int no = cost[0];
        int yes = cost[1];
        for (int i = 2; i < len; i++) {
            int tmp = no;
            no = yes;
            yes = Math.min(tmp, yes) + cost[i];
        }
        return Math.min(no, yes);
    }
}