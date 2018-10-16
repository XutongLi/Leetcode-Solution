//dp[i]表示第i个元素之前到第i个元素保持步长的数量
//如1,2,3，dp分别为0,1,2
//当步长变化时在i处重新计算步长，并将dp[i]设为1
//设好dp数组后，查找>=2的值(dp[i]=2，表示i前有2个步长相同的，yui构成了3个)
//将他们减1再累加,
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if (A == null || A.length < 2) return 0;
        int[] dp = new int[A.length];
        dp[0] = 0;
        dp[1] = 1;
        int res = 0, step = A[1] - A[0];
        for (int i = 2; i < A.length; i++) {
            if (A[i] - A[i - 1] == step) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = 1;
                step = A[i] - A[i - 1];
            }
            if (dp[i] >= 2)
                res += dp[i] - 1;
        }
        return res;
    }
}