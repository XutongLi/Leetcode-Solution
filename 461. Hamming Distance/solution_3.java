class Solution {
    public int hammingDistance(int x, int y) {
        int dis = 0;
        while (x > 0 && y > 0) {
            if ((x & 1) != (y & 1))
                dis ++;
            x >>= 1;
            y >>= 1;
        }
        while (x > 0) {
            if ((x & 1) == 1)
                dis ++;
            x >>= 1;
        }
        while (y > 0) {
            if ((y & 1) == 1)
                dis ++;
            y >>= 1;
        }
        return dis;
    }
}