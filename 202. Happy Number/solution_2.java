//使用环检测算法
class Solution {
    public boolean isHappy(int n) {
        int slow = n, fast = sqSum(n);
        while (slow != fast) {
            slow = sqSum(slow);
            fast = sqSum(sqSum(fast));
        }
        if (slow == 1)
            return true;
        else 
            return false;
    }
    private int sqSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += Math.pow(n % 10, 2);
            n = n / 10;
        }
        return sum;
    }
}