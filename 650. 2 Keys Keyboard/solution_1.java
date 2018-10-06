//n%i==0,  T(n)=i+T(n/i)
class Solution {
    public int minSteps(int n) {
        for (int i = 2; i <= n; i++) {
            if (n % i == 0)
                return i + minSteps(n / i);
        }
        return 0;
    }
}