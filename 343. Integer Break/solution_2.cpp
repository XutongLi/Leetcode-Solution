class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int prod = 1;
        while (n > 4) {
            prod *= 3;
            n -= 3;
        }
        return n * prod;
    }
};
//math solution
//time O(n) space O(1)
//https://leetcode.com/problems/integer-break/discuss/80689/A-simple-explanation-of-the-math-part-and-a-O(n)-solution