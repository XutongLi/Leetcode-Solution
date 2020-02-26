class Solution {
public:
    string convertToTitle(int n) {
        string res("");
        while (n > 0) {
            int mode = n % 26;
            res = string(1, (mode == 0 ? 26 : mode) - 1 + 'A') + res;
            n = mode == 0 ? n / 26 - 1 : n / 26;
        }
        return res;
    }
};