//hashset
class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> set = new HashSet<>();
        int sum = 0;
        while (true) {
            while (n != 0) {
                sum += Math.pow(n % 10, 2);
                n = n / 10;
            }
            if (sum == 1)
                return true;
            if (set.contains(sum))
                break;
            set.add(sum);
            n = sum;
            sum = 0;
        }
        return false;
    }
}