//time O(n)
//space O(1)
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int i = -1, j = A.length;
        while (true) {
            while (A[++i] % 2 == 0)
                if (i == A.length - 1) break;
            while (A[--j] % 2 == 1)
                if (j == 0) break;
            if (i >= j) return A;
            swap(A, i, j);
        }
    }
    private void swap(int[] A, int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
}