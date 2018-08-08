//recursive
//100%
class Solution {
    int i = 0;
    public int scoreOfParentheses(String S) {
        int res = 0;
        while (i < S.length()) {
            char c = S.charAt(i++);
            if (c == '(') {
                if (S.charAt(i) == ')') {
                    res += 1;
                    i++;
                } 
                else {
                    res += 2 * scoreOfParentheses(S);
                }    
            }
            else {
                return res;
            }
        }
        return res;
    }
}