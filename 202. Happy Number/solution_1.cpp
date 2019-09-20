class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int sum = 0;
        while (1) {
            while (n != 0) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            if (sum == 1)
                return true;
            if (s.find(sum) != s.end())
                return false;
            s.insert(sum);
            n = sum;
            sum = 0;
        }
        return false;
    }
};