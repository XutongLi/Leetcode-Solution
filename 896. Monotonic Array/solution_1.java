class Solution {
    public boolean isMonotonic(int[] A) {
        int flag = 0;
        for (int i = 0; i < A.length - 1; i++) {
            if (A[i + 1] > A[i]) {
                if (flag == -1) return false;
                flag = 1;
            }
            else if (A[i + 1] < A[i]) {
                if (flag == 1)  return false;
                flag = -1;
            }
        }
        return true;
    }
}