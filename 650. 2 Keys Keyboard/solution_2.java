class Solution {
    public int minSteps(int n) {
        int i = 2, step = 0;
        while (n > 1) {
            while (n % i == 0) {
                step += i;
                n /= i;
            }
            i++;
        }
        return step;
    }
}