class Solution {
public:
    int numTrees(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int res = 2 * numTrees(n - 1);  //n在1 -- n-1之外（即1 --  n-1节点相连）
        for (int i = 1; i <= n - 2; ++ i)   //n在1 -- n-1之内
            res += numTrees(i) * numTrees(n - 1 - i);
        return res;
    }
};