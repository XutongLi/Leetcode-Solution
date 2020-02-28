class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0)
            return s;
        int i = 0;
        for (int j = n - 1; j >= 0; -- j) {
            if (s[i] == s[j])
                ++ i;
        }
        if (i == n)
            return s;   //already palin
        string rev = s.substr(i);
        reverse(rev.begin(), rev.end());
        return rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};
//递归方法 hard to understand
//核心，找到的i不能为中点，且不与s中的其他字符配对，所以只能将i及之后的部分添加在s前，再对s.substr(0,i)做递归操作
//https://leetcode.com/problems/shortest-palindrome/discuss/60098/My-7-lines-recursive-Java-solution