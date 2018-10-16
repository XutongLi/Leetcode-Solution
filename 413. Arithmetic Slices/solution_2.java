//将solution_1空间复杂度从O(n)变为O(1)
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if (A == null || A.length <= 2) return 0;
        int res = 0, len = 1, step = A[1] - A[0];
        for (int i = 2; i < A.length; i++) {
            if (A[i] - A[i - 1] == step) {
                len ++;
            }
            else {
                step = A[i] - A[i - 1];
                len = 1;
            }
            if (len >= 2)
                res += len - 1;
        }
        return res;
    }
}