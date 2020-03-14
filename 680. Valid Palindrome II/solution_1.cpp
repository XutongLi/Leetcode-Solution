class Solution {
private:
    bool isP(const string &s, int i, int j) {
        while (i < j) {
            if (s[i ++] != s[j --])
                return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return isP(s, i + 1, j) || isP(s, i, j - 1);
            ++ i;   -- j;
        }
        return true;
    }
};
//time O(n) space O(1)