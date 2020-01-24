class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            while (l < n && !(isalpha(s[l]) || isdigit(s[l])))
                ++ l;
            while (r >= 0 && !(isalpha(s[r]) || isdigit(s[r])))
                -- r;
            if (!isalpha(s[l]) && !isdigit(s[l]) || !isalpha(s[r]) && !isdigit(s[r]))
                return true;    //遍历部分无数字与字母，算回文
            if (s[l] == s[r] || isalpha(s[l]) && isalpha(s[r]) && abs(s[l] - s[r]) == abs('a' - 'A')) {
                ++ l;
                -- r;
            }
            else
                return false;
        }
        return true;
    }
};