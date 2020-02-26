class Solution {
public:
    string convertToTitle(int n) {
        string res("");
        while (n > 0) {
            res = string(1, (-- n) % 26 + 'A') + res;
            n /= 26;
        }
        return res;
    }
};