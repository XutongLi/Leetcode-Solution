//100%
//base = j + n * i
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int m = nums.length;
        int n = nums[0].length;
        if (m * n != r * c || m == 1 && n == 1) {
            return nums;
        }
        int[][] result = new int[r][c]; 
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int base = j + c * i;
                result[i][j] = nums[base / n][base % n];
            }
        }
        return result;
    }
}