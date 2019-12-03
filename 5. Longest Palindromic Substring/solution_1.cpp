class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0)   return s;
        
        int start = 0, end = 0;
        for (int i = 0; i < n; i ++) {
            int len1 = subPLen(s, i, i);        //odd palindrome
            int len2 = subPLen(s, i, i + 1);    //even palidrome
            int len = max(len1, len2);
            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    int subPLen(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l --;
            r ++;
        }
        return r - l - 1;       
    }