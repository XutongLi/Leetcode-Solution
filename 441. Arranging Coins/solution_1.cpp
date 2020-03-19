class Solution {
public:
    int arrangeCoins(int n) {
        return floor((sqrt(1 + 8 * static_cast<long>(n)) - 1) / 2);
    }
};
// k(k + 1) / 2 = n
//k^2 + k - 2n = 0
//k = (sqrt(1 + 8n) - 1) / 2