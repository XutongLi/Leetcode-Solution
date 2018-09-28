//非happy数会有一个特点，在循环过程中会出现4这个值
class Solution {
    public boolean isHappy(int n) {
        while (true) {
            if (n == 4) return false;
            if (n == 1) return true;
            n = getSum(n);
        }
    }
    private int getSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += Math.pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
}