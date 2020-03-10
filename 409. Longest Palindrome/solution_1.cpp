class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(256, 0);
        int odd = 0, res = 0;
        for (auto c : s) {
            ++ cnt[c];
            if (cnt[c] % 2 == 0) {
                res += 2;
                odd -= 1;
            }
            else
                odd += 1;
        }
        return odd > 0 ? res + 1 : res; //若有奇数个的，可以中间补一个
    }
};
//time O(n) space O(1)