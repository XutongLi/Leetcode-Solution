class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty())
            return 0;
        int sum = 0;
        for (auto c : s) {
            sum = sum * 26 - 'A' + c + 1;
        }
        return sum;
    }
};