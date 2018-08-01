class Solution {
    public int[][] imageSmoother(int[][] M) {
        int m = M.length;
        int n = M[0].length;
        int[][] result = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n ; j++) {
                result[i][j] = getRes(M, i, j, m, n);
            }
        }
        return result;
    }
    
    int getRes(int[][] M, int x, int y, int m, int n) {
        int sum = 0;
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int xi = x + i;
                int yj = y + j;
                if (xi < 0 || xi >= m || yj < 0 || yj >= n) continue;
                count ++;
                sum += M[x + i][y + j];
            }
        }
        return sum / count;
    }
}